#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it: v)cin >> it;
    vector<int> tails;
    for (int i = 0; i < n; ++i) {
        if (tails.empty())tails.push_back(v[i]);
        else {
            auto pos = lower_bound(tails.begin(), tails.end(), v[i]);
            if (pos == tails.end())tails.push_back(v[i]);
            else *pos = v[i];
        }
    }
    cout << tails.size();
}