#include <bits/stdc++.h>

#define MAX_VAL 70000

using namespace std;

unordered_set<int> primes;

void computePrimes() {
    vector<int> values;

    values.push_back(2);
    values.push_back(3);
    values.push_back(5);
    values.push_back(7);
    values.push_back(11);

    bool notPrime;
    for (int i = 12; i < MAX_VAL; i++) {
        notPrime = false;
        for (int j = 0; j < values.size(); j++) {
            if (i % values[j] == 0) {
                notPrime = true;
                break;
            }
        }

        if (!notPrime) {
            values.push_back(i);
        }

    }

    copy(values.begin(), values.end(), inserter(primes, primes.end()));

}

int main() {
    int N;
    cin >> N;

    computePrimes();

    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        cout << (primes.find(val) != primes.end() ? "1" : "0") << endl;
    }

    return 0;
}