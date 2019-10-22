#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it:v)cin >> it;
    int C = *max_element(v.begin(), v.end());
    vector<vector<int>> dp(n, vector<int>(static_cast<unsigned long>(C + 1)));
    for (int j = 1; j <= C; ++j) {
        dp[0][j] = abs(v[0] - j);
    }
    vector<int> prefixMin(static_cast<unsigned long>(C + 1));

    prefixMin[1] = dp[0][1];
    for (int j = 2; j <= C; ++j) {
        prefixMin[j] = min(prefixMin[j - 1], dp[0][j]);
    }

    for (int i = 1; i < n; ++i) {
        int x = v[i];
        for (int j = 1; j <= C; ++j) {
            dp[i][j] = prefixMin[j] + abs(x - j);
        }
        prefixMin[1] = dp[i][1];
        for (int j = 2; j <= C; ++j) {
            prefixMin[j] = min(prefixMin[j - 1], dp[i][j]);
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j <= C; ++j) {
//            cout << dp[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
    dp[n - 1][0] = INT_MAX;

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
}
