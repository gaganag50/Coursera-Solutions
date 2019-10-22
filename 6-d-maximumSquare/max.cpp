#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &it:v) {
        for (auto &i:it)cin >> i;
    }

    vector<vector<int>> sum(n, vector<int>(n));
    sum[0][0] = v[0][0];
    for (int j = 1; j < n; ++j) {
        sum[0][j] = (v[0][j] + sum[0][j - 1]);
    }
    for (int i = 1; i < n; ++i) {
        sum[i][0] = (v[i][0] + sum[i - 1][0]);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            sum[i][j] = v[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int M = 0;
    for (int i = k - 1; i < n; ++i) {
        for (int j = k - 1; j < n; j++) {
            int total = sum[i][j];
            if (i >= k) {
                total -= sum[i - k][j];
            }
            if (j >= k) {
                total -= sum[i][j - k];

            }
            if (i >= k && j >= k) {
                total += sum[i - k][j - k];
            }
//            cout << total << ' ';
            M = max(M, total);

        }
    }
    cout << M ;
}