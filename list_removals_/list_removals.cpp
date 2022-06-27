#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <chrono>
#include <queue>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void print_vector(vector<int> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> take_values(vector<int> nums, int size) {
    for (int i = 0; i < size; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    return nums;
}



auto build(vector<int> arr, vector<int> tree, int size) {
    for (int i = 1; i < 2*size; i++) {
        tree.push_back(i);
    }
    for (int i = 0; i < size; i++) {
        tree[size+i] = arr[i];
    }
    for (int i = size - 1; i > 0; --i) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    return tree;
}



int main () {
    int size;
    cin >> size;
    vector<int> nums2;
    vector<int> nums;
    // Add 0 to the beginning of the array.
    
    nums = take_values(nums, size);
    nums2 = take_values(nums2, size);
    // Let's create the segment tree that represents the array.
    vector<int> tree; // Tree size.
    tree.push_back(0);
    auto tree2 = build(nums, tree, size + 1);
    print_vector(nums);
    print_vector(tree2);
    // auto start = high_resolution_clock::now();

    // for (int i = 0; i < size; i++) {
    //     handle_deletion(nums2[i]);
    // }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    // cout << duration.count() << endl;
    return 0;
}