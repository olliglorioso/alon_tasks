#include <string>;
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long check_if_eligible(long n) {
    // Lukujen 1...n summa voidaan laskea kaavalla (n*(n+1))/2. Jos summa on pariton, vastaus on NO.
    long sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << 0;
        return -1;
    } else {
        return sum;
    }
}

int main() {
    long n;
    cin >> n;
    long modulo = pow(10, 9) + 7;
    long sum = check_if_eligible(n);
    if (sum == -1) return 0;
    long answer = sum / 2;
    
    vector<vector<long>> sums(n,vector<long>(answer+1));
    sums[0][0] = 1;

    for (long a = 1; a < n; a++) {
        for (long b = 0; b <= answer; b++) {
            // Two possibilities: either we include a in the sum or not.
            // 1. We don't include it, and thus 
            long total = sums[a-1][b];
            long rem = b - a;
            if (rem >= 0) {
                total += sums[a-1][rem];
            }
            sums[a][b] = (total %= modulo);
        }
    }
    cout << sums[n-1][answer] << endl;
}