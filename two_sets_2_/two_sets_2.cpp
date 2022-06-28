#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int check_if_eligible(int n) {
    // Lukujen 1...n summa voidaan laskea kaavalla (n*(n+1))/2. Jos summa on pariton, vastaus on NO.
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << 0;
        return -1;
    } else {
        return sum;
    }
}

int main() {
    int n;
    cin >> n;
    int modulo = pow(10, 9) + 7;
    int sum = check_if_eligible(n);
    if (sum == -1) return 0;
    int answer = sum / 2;
    
    vector<int> numbers;
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    vector<vector<int>> sums(n,vector<int>(answer+1,0));
    sums[0][0] = 1;

    for (int a = 1; a < n; a++) {
        for (int b = 0; b <= answer; b++) {
            // Two possibilities: either we include a in the sum or not.
            // 1. We don't include it, and thus 
            int notIncluded = sums[a-1][b];
            // 1. We included it, and thus
            int included = sums[a-1][b-a];
            int total = notIncluded;
            if (b - a >= 0) {
                total = included + notIncluded;
                total %= modulo;
            } else {
                total %= modulo;
            }
            sums[a][b] = total;
        }
    }
    cout << sums[n-1][answer];
}