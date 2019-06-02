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

int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }

    return f;
}

int main() {
    int n, r;

    cin >> n >> r;

    cout << factorial(n) / (factorial(n - r) * factorial(r)) << endl;

    return 0;
}
