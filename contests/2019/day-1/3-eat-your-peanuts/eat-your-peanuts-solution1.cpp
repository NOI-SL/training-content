#include<iostream>
#include<vector>

using namespace std;

bool IsValid(const vector<int> &plates, int friends, int maxPerFriend) {
    int i = 0;
    int curSum = 0;
    while (i < plates.size() && friends > 0) {
        if (curSum + plates[i] <= maxPerFriend) {
            curSum += plates[i];
            ++i;
        } else {
            friends--;
            curSum = 0;
        }
    }
    return i >= plates.size();
}

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> plates(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> plates[i];
        sum += plates[i];
    }

    int l = -1, r = sum;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (IsValid(plates, f, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}