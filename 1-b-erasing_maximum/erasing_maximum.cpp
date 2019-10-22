#include <iostream>
#include <vector>
#include <climits>

int max(int a, int &b);

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> result;

    int m = INT_MIN, cnt = 0;
    for (int i = 0; i < n; ++i) {
        m = max(m, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == m)++cnt;
    }
    if (cnt == 1) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != m)result.push_back(a[i]);
        }
    } else {
        int c = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] != m)result.push_back(a[i]);
            else if (a[i] == m && c != 3) {
                result.push_back(a[i]);
                ++c;
            } else {
                ++c;
            }
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << result[i];
    }
    cout << endl;

    return 0;
}

int max(int a, int &b) {
    return a > b ? a : b;
}