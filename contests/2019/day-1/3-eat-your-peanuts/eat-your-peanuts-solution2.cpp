#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1000100;

int N, F;
int a[MAXN];

bool canEat(int maxPerHead) {
    int currentFriendPeanuts = 0;
    int friends = 1;

    for (int i = 0; i < N; ++i) {
        if (a[i] > maxPerHead) {
            return false;
        }
        if (currentFriendPeanuts + a[i] <= maxPerHead) {
            currentFriendPeanuts += a[i];
        } else {
            friends++;
            currentFriendPeanuts = a[i];
        }
    }

    return friends <= F;
}

int main() {
    int lo = 0, hi = 0;

    cin >> N >> F;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        hi += a[i];
    }


    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (canEat(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }

    cout << lo << endl;

    return 0;
}
