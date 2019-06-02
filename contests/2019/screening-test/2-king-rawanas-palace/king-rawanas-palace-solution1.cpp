#include <iostream>

using namespace std;

int s1, s2, r, d1, d2;
string words[4];

string answer(int number) {
    if (number % d1 == 0 && number % d2 == 0) {
        return words[2];
    }
    if (number % d1 == 0) {
        return words[0];
    }
    if (number % d2 == 0) {
        return words[1];
    }
    return words[3];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> r >> d1 >> d2;

        for (int j = 0; j < 4; j++) {
            cin >> words[j];
        }

        for (int j = 0; j < r; j++) {
            cout << answer(s1 + j) << " " << answer(s2 + j) << "\n";
        }
    }

    return 0;
}