#include <iostream>

using namespace std;

// n        0   1   2   3   4   5   ...
// fact(n)  1   1   2   6   24  120 ...
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int N;
    while (true) {
        cin >> N;

        if (N <= -1) {
            break;
        }

        cout << factorial(N) << endl;
    }
    return 0;
}