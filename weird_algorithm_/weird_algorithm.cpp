#include <iostream>
#include <vector>
#include <algorithm>
#include "BigInt.hpp"

using namespace std;

int main() {
    int k; 
    cin >> k; 
    BigInt n = k;
    vector<BigInt> nums;
    nums.push_back(n);
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        nums.push_back(n);
    }
    for_each(nums.begin(), nums.end(),
             [](const auto & elem){
                cout<<elem<<" "; 
        });
    cout << "\n";
}