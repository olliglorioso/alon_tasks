#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <map>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> coins;
 
    for (int i = 1; i <= n; i++) {
        // Get two numbers in one line as input
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    sort (coins.begin(), coins.end());
    int64_t result = 1;

    for (int64_t iteration = 0; coins[iteration] <= result && iteration < n; iteration++) {
        result += coins[iteration];
    }
    cout << result << endl;
}