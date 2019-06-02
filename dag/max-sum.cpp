#include <iostream>

using namespace std;

const int MX = 10000;
int arr[MX][MX];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int x = 0; x <= i; x++) {
            cin >> arr[i][x];
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                arr[i][j] += arr[i - 1][j];
            } else {
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
            }
        }
    }

    int best = arr[N - 1][0];
    for (int i = 0; i < N; i++) best = max(best, arr[N - 1][i]);

    cout << best << endl;
    return 0;
}
