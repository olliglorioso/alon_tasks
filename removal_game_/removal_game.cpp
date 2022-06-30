#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int whoseturn = 1;
int calculate_max_score(vector<int> nums) {
    for (int a = 0; a < nums.size(); a++) {
        for (int b = a + 1; b < nums.size(); b++){

        }
    }
}

int main () {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int res = calculate_max_score(nums);
    return 0;
}