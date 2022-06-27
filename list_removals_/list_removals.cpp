#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <chrono>
#include <queue>
#include <tuple>

using namespace std;

vector<int> nums;

int handle_deletion(int i) {
    i -= 1;
    cout << nums[i] << " ";
    nums.erase(nums.begin() + i);
}

int main () {
    int size;
    cin >> size;
    vector<int> nums2;
    
    // nums.insert(0)
    for (int i = 0; i < size; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    for (int i = 0; i < size; i++) {
        int a;
        cin >> a;
        nums2.push_back(a);
    }

    for (int i = 0; i < size; i++) {
        handle_deletion(nums2[i]);
    }
    return 0;
}