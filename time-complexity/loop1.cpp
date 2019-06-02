#include <iostream>

using namespace std;

void loop(int n) {
  cout << "Running a loop for N = " << n << endl;
  for (int i = 0; i < n; i++) {
    // i do nothing
  }
  cout << "Done running" << endl;
}

int main() {
  int N;
  cin >> N;
  loop(N);
  return 0;
}