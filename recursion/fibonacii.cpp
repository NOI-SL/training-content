#include <iostream>

using namespace std;

// n        0   1   2   3   4   5   6   ...
// fib(n)   0   1   1   2   3   5   8   ...
int fibonacii(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  return fibonacii(n - 1) + fibonacii(n - 2);
}

int main() {
  int N;
  while (true) {
    cin >> N;
    cout << fibonacii(N) << endl;
  }
  return 0;
}