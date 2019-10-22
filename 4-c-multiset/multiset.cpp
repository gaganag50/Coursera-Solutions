#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int temp[100005];
    int m = INT_MAX, M = INT_MIN;
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        m = min(m, l);
        M = max(M, r);
        ++temp[l];
        --temp[r + 1];
    }
    for (int i = 1; i < 100005; ++i) {
        temp[i] += temp[i - 1];
    }
    for (int i = m; i <= M; ++i) {
        if (temp[i] > 0)
            cout << i << ' ' << temp[i] << '\n';
    }
}