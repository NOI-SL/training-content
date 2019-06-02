// IOI 2019 Sri lankan screening
//
#include<bits/stdc++.h>

using namespace std;

struct Point {
    int y, x;

    Point(const int &y, const int &x) : y(y), x(x) {}

    Point() : y(0), x(0) {}
};

int FindShortest(vector<vector<int>> &maze, const Point start, const int &R, const int &C) {
    const int DIRS[4][2] = {{-1, 0},
                            {0,  1},
                            {1,  0},
                            {0,  -1}};
    queue<Point> q;
    maze[start.y][start.x] = 1;
    q.push(start);
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            Point next(cur.y + DIRS[i][0], cur.x + DIRS[i][1]);
            if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C ||
                maze[next.y][next.x] == -1 || maze[next.y][next.x] > 0) {
                continue;
            }
            if (maze[next.y][next.x] == -2) {
                return maze[cur.y][cur.x];
            }
            maze[next.y][next.x] = maze[cur.y][cur.x] + 1;
            q.push(next);
        }
    }
    return -1;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> maze(R, vector<int>(C, 0));
    Point start;

    // Read input
    string line;
    getline(cin, line);
    for (int r = 0; r < R; ++r) {
        getline(cin, line);
        for (int c = 0; c < C; ++c) {
            if (line[c] == '#') {
                maze[r][c] = -1;
            } else if (line[c] == 'S') {
                start = Point(r, c);
            } else if (line[c] == 'E') {
                maze[r][c] = -2;
            }
        }
    }

    cout << FindShortest(maze, start, R, C) << endl;
    return 0;
}


