#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    // int result = -1;

    // your code


    bool isFound = false;
    long long int a0 = 0;
    for (int i = 0; i < 1e8; ++i) {
//        cout << i << endl;
        if (a0 == z) {
            isFound = true;
            cout << i;
            break;
        }
        if ((i & 1) == 0) {
            a0 += x;
        } else {
            a0 -= y;

        }
//        cout << a0 << ' ';
    }

    if (!isFound)
        cout << -1;

    return 0;
}