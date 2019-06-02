#include <iostream>
#include <queue>

using namespace std;

int r, c;

struct Pos {
    int row;
    int col;
    int time;

    Pos(int row, int col, int time) : row(row), col(col), time(time) {}
};

bool validPos(int row, int col) {
    return row >= 0 && row < r && col >= 0 && col < c;
}

int rMovements[] = {-1, 0, 1, 0};
int cMovements[] = {0, 1, 0, -1};

pair<int, int> findStart(string arr[]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 'S') {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(0, 0);
}

int solve(string arr[], pair<int, int> start) {
    queue<Pos> procQueue;

    procQueue.push(Pos(start.first, start.second, 0));
    arr[start.first][start.second] = '.';

    while (procQueue.size() > 0) {
        auto loc = procQueue.front();
        if (arr[loc.row][loc.col] == '.') {
            for (int i = 0; i < 4; i++) {
                if (validPos(loc.row + rMovements[i], loc.col + cMovements[i])) {
                    procQueue.push(
                            Pos(loc.row + rMovements[i], loc.col + cMovements[i], loc.time + 1));
                }
            }
            arr[loc.row][loc.col] = '#';
        }

        if (arr[loc.row][loc.col] == 'E') {
            return loc.time;
        }

        procQueue.pop();
    }

    return -1;
}


int main() {


    cin >> r >> c;

    string arr[r];

    for (int i = 0; i < r; i++) {
        cin >> arr[i];
    }

    auto start = findStart(arr);

    cout << solve(arr, start) << endl;


    return 0;
}