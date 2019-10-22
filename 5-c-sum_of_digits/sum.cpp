#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll sumOfDigits(int S, int L) {
    vector<vector<ll>> dp(static_cast<unsigned long>(S + 1), vector<ll>(static_cast<unsigned long>(L + 1)));
    for (int i = 0; i <= S; ++i)
        fill(dp[i].begin(), dp[i].end(), 0L);


    for (int r = 0; r <= S; ++r) {
        for (int c = 0; c <= L; ++c) {
            if (c == 0)dp[r][c] = 0;
            else if (r == 0)dp[r][c] = 1;
            else if (c == 1 && r >= 0 && r <= 9) {
                dp[r][c] = 1;
            } else {
                if (c == L) {
                    for (int i = 1; r - i >= 0 && i <= min(9, r); ++i) {


                        dp[r][c] += dp[r - i][c - 1];
                    }
                } else
                    for (int i = 0; r - i >= 0 && i <= min(9, r); ++i) {


                        dp[r][c] += dp[r - i][c - 1];
                    }
            }
        }
    }


    return dp[S][L];
}

int main() {
    int S, L;
    cin >> S >> L;
    if (S == 0)cout << 0;
    else
        cout << sumOfDigits(S, L);
}