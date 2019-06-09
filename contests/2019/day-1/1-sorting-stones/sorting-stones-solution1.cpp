// Author: Chethiya Abeysinghe
// Problem: Sorting Stones

#include<vector>
#include<iostream>

using namespace std;

int Sort(vector<int> &weights, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int swapCnt = 0;
    int wall = left;
    for (int i = left; i < right; ++i) {
        if (weights[i] < weights[right]) {
            if (wall != i) {
                std::swap(weights[i], weights[wall]);
                swapCnt++;
            }
            wall++;
        }
    }
    if (wall != right) {
        std::swap(weights[wall], weights[right]);
        swapCnt++;
    }
    return swapCnt + Sort(weights, left, wall - 1) + Sort(weights, wall + 1, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << Sort(weights, 0, n - 1) << endl;
    for (int i = 0; i < n - 1; ++i) {
        assert(weights[i] < weights[i + 1]);
    }
    return 0;
}