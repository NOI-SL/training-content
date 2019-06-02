// IOI Sri Lanka screening 2019
// Author: chethiya

#include<bits/stdc++.h>

using namespace std;

struct Hash {
    size_t operator()(const pair<int, int> &p) const {
        return std::hash<int>()(p.first * 100 + p.second);
    }
};

int main() {
    int size, steps;
    pair<int, int> start;
    cin >> size;
    cin >> start.first >> start.second;
    cin >> steps;
    start.first--;
    start.second--;

    const int DIRS[4][2] = {{-1, 0},
                            {0,  1},
                            {1,  0},
                            {0,  -1}};

    unordered_set<pair<int, int>, Hash> ps[2];
    int cur = 1, next = 0;
    ps[0].insert(start);

    for (int ss = 0; ss < steps; ++ss) {
        cur = next;
        next = (next + 1) % 2;
        ps[next].clear();

        unordered_set<pair<int, int>, Hash> possibles;
        for (const auto &p: ps[cur]) {
            for (int i = 0; i < 4; ++i) {
                int y = p.first + DIRS[i][0];
                int x = p.second + DIRS[i][1];
                if (y < 0 || y >= size || x < 0 || x >= size) {
                    continue;
                }
                possibles.insert(make_pair(y, x));
            }
        }

        for (const auto &p: possibles) {
            int cnt = 0;
            for (int i = 0; i < 4; ++i) {
                pair<int, int> n = make_pair(p.first + DIRS[i][0], p.second + DIRS[i][1]);
                if (ps[cur].find(n) != ps[cur].end()) {
                    cnt++;
                }
            }
            if (cnt == 1 || cnt == 3) {
                ps[next].insert(p);
            }
        }
    }

    cout << ps[next].size() << endl;
}