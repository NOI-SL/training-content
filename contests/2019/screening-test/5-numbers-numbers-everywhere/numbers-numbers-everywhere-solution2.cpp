// IOI Sri Lanka Screening 2019
// Author: Chethiya

#include<bits/stdc++.h>

using namespace std;

string Int2Text(int n) {
    const string thousandPow[4] = {"", "thousand", "million", "billion"};
    const string ones[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const string tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const string elevens[10] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                                "eighteen", "nineteen"};
    const string hundred = "hundred";
    auto Small2Text = [&ones, &tens, &elevens, &hundred](int n) -> string {
        vector<string> words;
        if (n >= 100) {
            words.push_back(ones[n / 100] + " " + hundred);
            n %= 100;
        }
        if (n >= 10) {
            if (n > 10 && n < 20) {
                words.push_back(elevens[n - 10]);
                n = 0;
            } else {
                words.push_back(tens[n / 10]);
                n %= 10;
            }
        }
        if (n > 0) {
            words.push_back(ones[n]);
        }
        ostringstream oss;
        bool first = true;
        for (const auto &w: words) {
            if (first) {
                first = false;
            } else {
                oss << " ";
            }
            oss << w;
        }
        return oss.str();
    };

    int pow = -1;
    stack<string> res;
    if (n == 0) {
        res.push(ones[0]);
    }
    while (n > 0) {
        ++pow;
        int remain = n % 1000;
        n /= 1000;
        if (remain == 0) {
            continue;
        }
        if (pow > 0) {
            res.push(Small2Text(remain) + " " + thousandPow[pow]);
        } else {
            res.push(Small2Text(remain));
        }
    }
    bool first = true;
    ostringstream oss;
    while (!res.empty()) {
        if (first) {
            first = false;
        } else {
            oss << " ";
        }
        oss << res.top();
        res.pop();
    }
    return oss.str();
}

int main() {
    int n;
    cin >> n;
    cout << Int2Text(n) << endl;
}
