#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll editDist(const string &str1, long int n, const string &str2, long int m, int I, int D, int S) {
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                if (i == 0) dp[i][j] = I * j;
                else dp[i][j] = D * i;
            } else {
                if (str1[i - 1] == str2[j - 1])dp[i][j] = dp[i - 1][j - 1];
                else {
                    ll d = dp[i - 1][j];  // delete char from first
                    ll in = dp[i][j - 1];  // insert char into first
                    ll s = dp[i - 1][j - 1];  // substitute
                    dp[i][j] = min(d + D, min(s + S, in + I));

                }
            }

        }
    }
    /*for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << '\n';*/

    return dp[n][m];
}

int main() {

    int I, D, S;

    long int n, m;
    cin >> n >> m;
    string str1, str2;
    cin >> str1 >> str2;
    cin >> I >> D >> S;
    printf("%lli\n", editDist(str1, n, str2, m, I, D, S));

}