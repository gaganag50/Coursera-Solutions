#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(15);
    vector<int> v(n);
    for (auto &it:v)cin >> it;
    /*for (int i = 0; i < n; ++i) {
        v[i] = 100000000;
    }*/
//    int idx = 1;
    /*for (auto it: v) {
        cout << idx++ << ' ' << it << '\n';
    }*/
    long long fsum = accumulate(v.begin(), v.end(), 0L);
//    cout << endl;

    long double ssum = 0;
    for (auto it:v) {
        ssum += (1/(long double)it);
    }

//    cout << ssum << " " << fsum << endl;
    cout  << ssum + fsum << '\n';

}