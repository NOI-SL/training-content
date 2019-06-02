#include <iostream>
#include <vector>

using namespace std;

string getUnitInWords(int unit) {
    const string basics[] = {
            "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
            "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
            "eighteen", "nineteen"
    };
    const string bigOnes[] = {
            "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    if (unit < 20) return basics[unit - 1];
    return bigOnes[unit / 10 - 2];
}

string getBlockInWords(int block) {
    vector<string> words;
    if (block / 100) {
        words.push_back(getUnitInWords(block / 100));
        words.push_back("hundred");
        block %= 100;
    }

    if (!block);
    else if (block < 20) {
        words.push_back(getUnitInWords(block));
    } else {
        words.push_back(getUnitInWords((block / 10) * 10));
        block %= 10;
        if (block) words.push_back(getUnitInWords(block));
    }

    string output = "";
    for (int i = 0; i < words.size(); i++) {
        if (i) output += " ";
        output += words[i];
    }

    return output;
}

string getNumberInWords(int number) {
    if (!number) return "zero";

    string suffixes[] = {"billion", "million", "thousand"};
    int divisor = 1000000000;
    int suffixIndex = 0;

    vector<string> blocks;

    while (number > 0) {
        int block = number / divisor;
        if (block) {
            blocks.push_back(getBlockInWords(block));
            if (suffixIndex < 3) blocks.push_back(suffixes[suffixIndex]);
        }
        number %= divisor;
        divisor /= 1000;
        suffixIndex++;
    }

    string output = "";
    for (int i = 0; i < blocks.size(); i++) {
        if (i) output += " ";
        output += blocks[i];
    }

    return output;
}

int main() {
    int number;
    cin >> number;
    cout << getNumberInWords(number) << endl;
    return 0;
}