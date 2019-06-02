#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

int N, R;

int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }

    return f;
}

int main() {
    int s[2];
    int d[2];
    string str[4];

    cin >> N;

    for (int t = 0; t < N; ++t) {
        cin >> s[0] >> s[1] >> R >> d[0] >> d[1];
        cin >> str[1] >> str[2] >> str[3] >> str[0];

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < 2; ++j) {
                int idx = 0;
                for (int k = 0; k < 2; ++k) {
                    if (s[j] % d[k] == 0) {
                        idx += 1 << k;
                    }
                }
                cout << str[idx];
                if (j == 0) {
                    cout << " ";
                } else {
                    cout << endl;
                }

                s[j]++;
            }
        }
    }

    return 0;
}
