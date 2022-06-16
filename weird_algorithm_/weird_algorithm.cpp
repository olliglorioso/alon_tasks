#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; 
    cin >> n; 
    vector<int> nums;
    nums.push_back(n);
    while (n != 1 && n > 0) {
        cout << n;
        cout << "\n";
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