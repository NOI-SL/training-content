#include <iostream>

using namespace std;

int ncr(int N, int R) {
    int output = 1;
    for (int i = N; i > N - R; i--) output *= i;
    for (int i = R; i >= 1; i--) output /= i;
    return output;
}

int main() {
    int N, R;
    cin >> N >> R;
    cout << ncr(N, R) << endl;
    return 0;
}