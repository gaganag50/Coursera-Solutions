#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;

int main() {
    int r, c;
    cin >> r >> c;
    int result = 0;
    int R = min(r, c), C = max(r, c);
    std::vector<int> v1(MAX_N);

    int a = 0;
    for (int i = 1; i < MAX_N; i += 3, a += (3 - 1)) {
        v1[i] = a;
        v1[i + 1] = a + (1);
        v1[i + 2] = a + 2;
    }
    if (R == 1) {
        cout << v1[C];
    } else {
        std::vector<int> v2(MAX_N);
        a = v1[R];
        for (int i = 1; i < MAX_N; i += 3, a += (R + R + v1[R])) {
            v2[i] = a;
            v2[i + 1] = a + (R);
            v2[i + 2] = a + R + R;
        }
        // for(auto it: v2)cout << it << ' ';
        cout << v2[C];
    }
}


    // 








