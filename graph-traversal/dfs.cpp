#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, p, s;
    cin >> n >> p >> s;

    bool paths[n][n];

    memset(paths, 0, sizeof(paths));

    for (int i = 0; i < p; i++) {
        int first, second;

        cin >> first >> second;

        paths[first][second] = true;
        paths[second][first] = true;
    }


    bool visited[n];

    memset(visited, 0, sizeof(visited));

    stack<int> stk;
    stk.push(s);

    vector<int> path;

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();
        if (!visited[current]) {
            path.push_back(current);

            visited[current] = true;

            for (int i = n -1; i >= 0; i--) {
                if (paths[current][i]) {
                    stk.push(i);
                }
            }
        }
    }

    for (auto city: path) {
        cout << city << " ";
    }

    cout << endl;

    return 0;
}
