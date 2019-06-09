#include <iostream>

#define rep(a, b) for(int a=0;a<b;a++)
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int sort(int arr[], int N) {
    if (N <= 1) return 0;
    const int pivot = N - 1;
    int swaps = 0, wall = 0, tmp;

    rep(i, N - 1) if (arr[i] < arr[pivot]) {
            if (i != wall) swaps++;
            swap(arr[wall], arr[i]);
            wall++;
        }

    if (pivot != wall) swaps++;
    swap(arr[wall], arr[pivot]);
    swaps += sort(arr, wall);
    swaps += sort(arr + wall + 1, N - 1 - wall);
    return swaps;
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    rep(i, N) cin >> arr[i];

    cout << sort(arr, N) << endl;

    rep(i, N - 1) if (arr[i] > arr[i + 1]) throw ("BAD SORT");
    return 0;
}
