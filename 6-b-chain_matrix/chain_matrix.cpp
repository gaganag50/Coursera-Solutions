#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> m(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> m[i];

    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        dp[i][i + 1] = dp[i][i] + dp[i + 1][i + 1] + m[i] * m[i + 1] * m[i + 2];
    }


    int len = 3;
    while (len <= n) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + m[i] * m[k + 1] * m[j + 1]);
            }
        }

        ++len;
    }


    cout << dp[0][n - 1] << endl;

    return 0;
}