#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int64_t check_if_eligible(int64_t n) {
    // Lukujen 1...n summa voidaan laskea kaavalla (n*(n+1))/2. Jos summa on pariton, vastaus on NO.
    int64_t sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << 0;
        return -1;
    } else {
        return sum;
    }
}

int main() {
    int64_t n;
    cin >> n;
    int64_t modulo = pow(10, 9) + 7;
    int64_t sum = check_if_eligible(n);
    if (sum == -1) return 0;
    int64_t answer = sum / 2;
    
    vector<int64_t> numbers;
    for (int64_t i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    vector<vector<int64_t>> sums(n,vector<int64_t>(answer+1,0));
    sums[0][0] = 1;

    for (int64_t a = 1; a < n; a++) {
        for (int64_t b = 0; b <= answer; b++) {
            // Two possibilities: either we include a in the sum or not.
            // 1. We don't include it, and thus 
            int64_t notIncluded = sums[a-1][b];
            // 1. We included it, and thus
            int64_t included = sums[a-1][b-a];
            int64_t total = notIncluded;
            if (b - a >= 0) {
                total = included + notIncluded;
                total %= modulo;
            } else {
                total %= modulo;
            }
            sums[a][b] = total;
        }
    }
    cout << sums[n-1][answer] << endl;
}