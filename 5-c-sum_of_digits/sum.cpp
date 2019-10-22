#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll sumOfDigits(int S, int L) {
    vector<vector<ll>> dp(static_cast<unsigned long>(L), vector<ll>(static_cast<unsigned long>(S + 1)));


    for (int len = 0; len < L; ++len)
        fill(dp[len].begin(), dp[len].end(), 0L);

    for (int len = 0; len < L-1; ++len) {
        dp[len][0] = 1;
    }

    for (int sum = 1; sum <= min(9, S); ++sum) {
        dp[0][sum] = 1;       // 1 length
    }

    for (int len = 1; len < L; ++len) {     // length->2 to L
        for (int sum = 1; sum <= S; ++sum) {


            if (len == L - 1) {
                for (int digit = 1; sum >= digit && digit <= 9; ++digit) {


                    dp[len][sum] += dp[len - 1][sum - digit];
                }
            } else
                for (int digit = 0; sum >= digit  && digit <= 9; ++digit) {


                    dp[len][sum] += dp[len - 1][sum - digit];
                }

        }
    }

    return dp[L - 1][S];
}

int main() {
    int S, L;
    cin >> S >> L;
    if (L == 0)cout << 0;
    else if(S == 0 && L == 1)cout << 1;
    else if(S == 0 )cout << 0;

    else
        cout << sumOfDigits(S, L);
}
