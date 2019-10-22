#include<bits/stdc++.h>

using namespace std;

vector<int> smallestInWin(vector<int> v, int n, int k) {
    stack<int> s;
    s.push(0);
    vector<int> small(n);
    for (int i = 1; i < n; ++i) {
        while (!s.empty() && v[s.top()] > v[i]) {
            small[s.top()] = i - 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        small[s.top()] = n - 1;
        s.pop();
    }
    int j = 0;
    vector<int> res;
    for (int i = 0; i < n - k + 1; ++i) {
        while (j < i || small[j] < i + k - 1) {
            ++j;
        }
        res.push_back(v[j]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it: v)cin >> it;
    long long sum = 0;
    for (int len = 1; len <= n; ++len) {
        vector<int> res = smallestInWin(v, n, len);
        sum += accumulate(res.begin(), res.end(), 0);
    }
    cout << sum;
}