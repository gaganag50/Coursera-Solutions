#include <bits/stdc++.h>

using namespace std;

struct item {
    int weight, value;

    bool operator<(const item &other) const {
        return weight < other.weight;
    }
};

int main() {
    int n, W;
    cin >> n >> W;
    vector<item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight;
        cin >> items[i].value;
    }
    sort(items.rbegin(), items.rend());
    long long totalValue = 0;
    vector<int> candidates;
    for (int wt = 0; wt <= 30; ++wt) {
        int weight = (1 << wt);
        while (!items.empty() && items.back().weight == weight) {
            candidates.push_back(items.back().value);
            items.pop_back();
        }
        sort(candidates.begin(), candidates.end());
        if (W & weight) {
            if(!candidates.empty()){
                totalValue += candidates.back();
                candidates.pop_back();
            }
            
        }
        vector<int> newCandidates;
        int newValue = 0;
        while (candidates.size() >= 2) {
            newValue += candidates.back();
            candidates.pop_back();
            newValue += candidates.back();
            candidates.pop_back();
            newCandidates.push_back(newValue);
        }
        if (candidates.size() == 1) {
            newCandidates.push_back(candidates.back());
            candidates.pop_back();
        }
        candidates = newCandidates;
    }
    cout << totalValue << '\n';
}