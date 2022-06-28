#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long check_if_eligible(long long n) {
    // Lukujen 1...n summa voidaan laskea kaavalla (n*(n+1))/2. Jos summa on pariton, vastaus on NO.
    long long sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << 0;
        return -1;
    } else {
        return sum;
    }
}
vector<vector<long long>> sums;
int main() {
    long long n;
    cin >> n;
    long long modulo = pow(10, 9) + 7;
    long long sum = check_if_eligible(n);
    if (sum == -1) return 0;
    long long answer = sum / 2;
    
    vector<long long> numbers;
    for (long long i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    
    sums.resize(n,vector<long long>(answer+1,0));
    sums[0][0] = 1;

    for (long long a = 1; a < n; a++) {
        for (long long b = 0; b <= answer; b++) {
            // Two possibilities: either we include a in the sum or not.
            // 1. We don't include it, and thus 
            long long notIncluded = sums[a-1][b];
            // 1. We included it, and thus
            long long included = sums[a-1][b-a];
            long long total = notIncluded;
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
    return 0;
}