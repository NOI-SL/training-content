#include <iostream>

using namespace std;

void sort(int N, int array[]) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];

        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  int N;
  cin >> N;
  int array[N];
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  cout << "Going to sort the input array" << endl;
  sort(N, array);
  cout << "Sorted" << endl;

  for (int i = 0; i < N; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;
  return 0;
}