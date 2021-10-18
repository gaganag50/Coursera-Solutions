#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    double eps = 1e-6;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    double sumsum1 = std::accumulate(a.begin(), a.end(), 0.0);
    double sumsum2 = std::accumulate(b.begin(), b.end(), 0.0);

    bool equal_sum = false;
    bool sum_a_larger = false;
//    cout << sumsum1 << ' ' << sumsum2 << ' ' << sumsum1 - sumsum2 << endl;
    if (abs(sumsum1 - sumsum2) < eps) {
        equal_sum = true;
    }
    if (sumsum2 < sumsum1 - eps)sum_a_larger = true;
    if (equal_sum)
        cout << "SUM(A)=SUM(B)" << endl;
    else if (sum_a_larger)
        cout << "SUM(A)>SUM(B)" << endl;
    else
        cout << "SUM(A)<SUM(B)" << enl;

    return 0;
}
