#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <map>
using namespace std;


int factorial_of (int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial_of(num - 1);
    }
}
vector<string> strings;
void permutation (string s, int start, int end) {
    if (start == end) {
        strings.push_back(s);
    } else {
        for (int i = start; i <= end; i++) {
            swap(s[start], s[i]);
            permutation(s, start + 1, end);
            swap(s[start], s[i]);
        }
    }
}

int main() {
    string s;
    cin >> s;
    // Map of letters
    map<string, int> letters;
    for (int i = 0; i < s.size(); i++) {
        string letter = s.substr(i, 1);
        // If letter is not in map, add it
        if (letters.find(letter) == letters.end()) {
            letters[letter] = 1;
        } else {
            letters[letter]++;
        }
    }
    
    // Let's count how many possibilities there are with the theorem n/n_1!*n_2!*...*n_n!
    int n = factorial_of(s.size());
    int fac = 1;
    for (auto element : letters) {
        if (element.second != 1) {
            fac *= factorial_of(element.second);
        }
    }
    int possibilities = n / fac;
    cout << possibilities << endl;
    // Generate all different string that can be created using characters in letters
    permutation(s, 0, s.size() - 1);
    // Sort all strings
    sort(strings.begin(), strings.end());
    // // Remove duplicates
    strings.erase(unique(strings.begin(), strings.end()), strings.end());
    // Print all strings
    for (auto element : strings) {
        cout << element << endl;
    }
}