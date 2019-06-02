#include <iostream>

using namespace std;

void merge(int N, int array[]) {
  int merged[N];
  int mid = N / 2;
  int left = 0, right = 0;
  int mergedIndex = 0;

  while (left < mid && right < N - mid) {
    if (array[left] < array[mid + right]) {
      merged[mergedIndex] = array[left];
      left++;
    } else {
      merged[mergedIndex] = array[mid + right];
      right++;
    }
    mergedIndex++;
  }

  while (left < mid) {
    merged[mergedIndex] = array[left];
    mergedIndex++;
    left++;
  }

  while (right < N - mid) {
    merged[mergedIndex] = array[mid + right];
    mergedIndex++;
    right++;
  }

  // copy the result to original array
  for (int i = 0; i < N; i++) {
    array[i] = merged[i];
  }
}

void sort(int N, int array[]) {
  if (N <= 1) return;
  int mid = N / 2;

  sort(mid, array);
  sort(N - mid, array + mid);
  merge(N, array);
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