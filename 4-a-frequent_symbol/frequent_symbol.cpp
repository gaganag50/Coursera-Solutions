#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int q;
    cin >> q;
    vector<int> freq[26];
    int idx = 0;
    for (char it:str) {
        freq[it - 'a'].push_back(idx);
        ++idx;
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        long M = 0;
        char ans;
        for (int a = 0; a < 26; ++a) {
            auto low = lower_bound(freq[a].begin(), freq[a].end(), l - 1);
            auto high = upper_bound(freq[a].begin(), freq[a].end(), r - 1);
            if (M < high - low) {
                M = high - low;
                ans = char('a' + a);
            }
        }
        printf("%c\n",ans);
    }
}