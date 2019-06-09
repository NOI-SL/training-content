// Author: Chethiay Abeysinghe
// Proble: Mouse in the Exploding Maze

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct State {
    int y, x;
    int distance;
    bool second;

    State(int y, int x, int distance) : y(y), x(x), distance(distance), second(false) {}

    State(int y, int x, int distance, bool second) : y(y), x(x), distance(distance), second(second) {}

};

const int END = -1;

const int WALL = -2;
const int VISITED = -3;

const int ON = 0;
const int OFF = 1;

const int EMPTY = 2;

const int DIRS[4][2] = {{-1, 0},
                        {0,  1},
                        {1,  0},
                        {0,  -1}};

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, EMPTY));
    queue<State> q;
    for (int i = 0; i < r; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < c; ++j) {
            if (line[j] == 'E') {
                grid[i][j] = END;
            } else if (line[j] == '#') {
                grid[i][j] = WALL;
            } else if (line[j] == 'N') {
                grid[i][j] = ON;
            } else if (line[j] == 'F') {
                grid[i][j] = OFF;
            } else if (line[j] == 'S') {
                grid[i][j] = VISITED;
                q.push(State(i, j, 0));
            }
        }
    }

    int result = -1;
    while (!q.empty() && result == -1) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int y = cur.y + DIRS[i][0];
            int x = cur.x + DIRS[i][1];
            if (y < 0 || y >= r || x < 0 || x >= c || grid[y][x] == WALL || grid[y][x] == VISITED) {
                continue;
            }
            int distance = cur.distance + 1;
            if (grid[y][x] == END) {
                result = distance;
                break;
            }
            if (grid[y][x] == EMPTY || grid[y][x] != distance % 2) {
                q.push(State(y, x, distance, grid[y][x] != EMPTY));
                grid[y][x] = VISITED;
            }
        }
        if (!cur.second) {
            q.push(State(cur.y, cur.x, cur.distance + 1, true));
        }
    }
    cout << result << endl;
    return 0;
}