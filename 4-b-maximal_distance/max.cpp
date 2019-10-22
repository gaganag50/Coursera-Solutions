#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    priority_queue<pii> maxHeap;
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    int i = 1;
    while (n--) {
        int x;
        cin >> x;
        minHeap.push({x, i});
        maxHeap.push({x, i});
        int xa = minHeap.top().second, xb = maxHeap.top().second;
        cout << min(xa, xb) << ' ' << max(xa, xb) << '\n';
        ++i;
    }
}