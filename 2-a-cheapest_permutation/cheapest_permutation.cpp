#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int computer_cost(vector<vector<int> > A, vector<int> v) {
    int n = v.size(), cost = 0;
    for (int i = 0; i < n - 1; ++i) {
        cost += (A[v[i]-1][v[i + 1]-1]);
    }
    return cost;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    vector<int> result(n);

    // your code
    std::iota(result.begin(), result.end(), 1);
    int cost = INT_MAX;
    vector<int> ans;
    do {
        int c = computer_cost(a, result);
        if (cost > c) {
            cost = c;
            ans = result;
        }
    } while (std::next_permutation(result.begin(), result.end()));
    result = ans;
    for (int i = 0; i < result.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << result[i];
    }
    cout << endl;

    return 0;
}