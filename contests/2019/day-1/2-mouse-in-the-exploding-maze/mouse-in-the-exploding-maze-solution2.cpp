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

const int MAX = 1100;
const int DX[5] = {0, 0, 0, -1, +1};
const int DY[5] = {0, -1, +1, 0, 0};

int R, C;
string a[MAX];
struct QueueElem {
    int r, c;
    int t;
};
QueueElem queue[MAX * MAX];
bool v[MAX][MAX][2];

bool isBombOn(int r, int c, int t) {
    if (a[r][c] == 'N' && t == 0) {
        return true;
    }
    if (a[r][c] == 'F' && t == 1) {
        return true;
    }

    return false;
}

int bfs(int sr, int sc) {
    queue[0] = {sr, sc, 0};
    int Q = 1;

    for (int q = 0; q < Q; ++q) {
        QueueElem e = queue[q];
        int nextT = (e.t + 1) % 2;
        for (int i = 0; i < 5; ++i) {
            int r = e.r + DY[i];
            int c = e.c + DX[i];
            if (r < 0 || r >= R || c < 0 || c >= C) continue;
            if (a[r][c] == '#') continue;
            if (v[r][c][nextT]) continue;
            if (isBombOn(r, c, nextT)) continue;

            v[r][c][nextT] = true;
            queue[Q++] = {r, c, e.t + 1};

            if (a[r][c] == 'E') {
                return e.t + 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> R >> C;
    int sr = 0, sc = 0;

    for (int r = 0; r < R; ++r) {
        cin >> a[r];
        for (int c = 0; c < C; ++c) {
            if (a[r][c] == 'S') {
                sr = r;
                sc = c;
            }
        }
    }

    cout << bfs(sr, sc) << endl;

    return 0;
}
