#include <bits/stdc++.h>

using namespace std;

vector<string> tokenize(string str) {
    char *token = strtok(const_cast<char *>(str.c_str()), "+-");
    vector<string> v;
    while (token != nullptr) {
        v.emplace_back(token);
        token = strtok(nullptr, "+-");
    }
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<string> v = tokenize(str);
    vector<char> symbols;
    for (char ch: str) {
        if (ch == '+' || ch == '-') {
            symbols.emplace_back(ch);
        }
    }
    long long int ans = stoll(v[0]);
    for (int i = 0, j = 0; i < (int) v.size() - 1; ++i, ++j) {
        if (symbols[j] == '+')
            ans += stoll(v[i + 1]);
        else ans -= stoll(v[i + 1]);
    }
    cout << ans;
}