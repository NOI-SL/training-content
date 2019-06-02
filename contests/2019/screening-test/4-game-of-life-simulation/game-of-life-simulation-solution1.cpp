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
#define MAXN 110

bool a[MAXN][MAXN][MAXN];
int N, S;
const int dx[4] = {-1, +1, 0, 0};
const int dy[4] = {0, 0, -1, +1};

int main() {
    int r, c;

    cin >> N >> r >> c >> S;

    a[0][r - 1][c - 1] = true;

    for (int i = 1; i <= S; ++i) {
        for (r = 0; r < N; ++r) {
            for (c = 0; c < N; ++c) {
                for (int d = 0; d < 4; ++d) {
                    int x = c + dx[d];
                    int y = r + dy[d];
                    if (0 <= x && x < N && 0 <= y && y < N) {
                        a[i][y][x] ^= a[i - 1][r][c];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (r = 0; r < N; ++r) {
        for (c = 0; c < N; ++c) {
            if (a[S][r][c]) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
