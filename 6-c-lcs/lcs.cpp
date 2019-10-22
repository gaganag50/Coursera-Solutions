#include <bits/stdc++.h>

using namespace std;

void lcs(vector<int> s1, vector<int> s2, int n) {
    vector<vector<long int>> dp(n + 1, vector<long int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    long size = dp[n][n];
    cout << size << '\n';
    vector<int> ans1(size);
    vector<int> ans2(size);
    unsigned long k = size - 1;
    for (int i = n, j = n; i > 0 && j > 0;) {
        if (s1[i - 1] == s2[j - 1]) {
            ans1[k] = (i - 1);
            ans2[k] = (j - 1);
            --k;
            --i;
            --j;

        } else if (dp[i][j] == dp[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }
    for (auto it: ans1)cout << it << ' ';
    cout << '\n';
    for (auto it: ans2)cout << it << ' ';
}

int main() {
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (auto &it: v1)cin >> it;
    for (auto &it: v2)cin >> it;

    lcs(v1, v2, n);


}