#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, p, s; // n: number of cities(nodes), p: number of paths(edges), s: starting position
    cin >> n >> p >> s;

    bool paths[n][n]; // Creating the adjacency matrix

    memset(paths, 0, sizeof(paths)); // Clearing the Garbage Values in the adjacency matrix

    // Read all the path from the input
    for (int i = 0; i < p; i++) {
        int first, second;

        cin >> first >> second;

        paths[first][second] = true; // Mark that there is a path from first -> second
        paths[second][first] = true; // Mark that there is a path from second -> first
    }


    bool visited[n]; // Array used to check whether we already visited a specific node

    memset(visited, 0, sizeof(visited)); // Clearing the Garbage values of the array and setting everything to 0(false)

    stack<int> stk; // A Stack is used for implementing DFS
    stk.push(s); // Start with the given starting node

    vector<int> path; // Vector used to store the nodes we visited

    // Loop that's run till there aren't anymore nodes to visit
    while (!stk.empty()) {
        // Get the node on the top, then remove it from the stack
        int current = stk.top();
        stk.pop();

        // If that node hasn't been visited, visit the node
        if (!visited[current]) {

            path.push_back(current); // Add it to the list of nodes, visited

            visited[current] = true; // Mark that we visited this node

            // Find All the paths starting from this node to the others & add them to the stack to be processed
            // Looping from n-1 to 0, because we want to visit the nodes with lowest values first
            for (int i = n -1; i >= 0; i--) {
                if (paths[current][i]) {
                    stk.push(i);
                }
            }
        }
    }

    // Print the nodes in the order they were visited
    for (auto city: path) {
        cout << city << " ";
    }

    cout << endl;

    return 0;
}
