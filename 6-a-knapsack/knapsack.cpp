#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> v[i];

    vector<int> result;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if (j - w[i - 1] >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    for (int i = n, j = W; i >= 1; --i) {
        if (dp[i][j] != dp[i - 1][j]) {
            result.push_back(i);
            j -= w[i - 1];
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << result[i];
    }
    cout << endl;

    return 0;
}