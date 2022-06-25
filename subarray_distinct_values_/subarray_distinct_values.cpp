#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace std::chrono;

// void print_vectors(vector<vector<int32_t>> vec) {
//     cout << "vector elements: " << endl;
//     for (int32_t i = 0; i < vec.size(); i++) {
//         cout << vec[i][0] << " and " << vec[i][1] << endl;
//     }
// }

// void print_vector(vector<int32_t> vec) {
//     cout << endl;
//     cout << "vector elements : ";
//     for (int32_t i = 0; i < vec.size(); i++) {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
// }

int main() {
    auto start = high_resolution_clock::now();
    int32_t n, d_elems; 
    cin >> n >> d_elems;
    vector<int32_t> vals;
    for (int32_t i = 0; i < n; i++) {
        int32_t a;
        cin >> a;
        vals.push_back(a);
    }
    int32_t count = 0;
    int32_t left_idx = 0;
    int32_t right_idx = 0;
    unordered_map<int32_t, int32_t> dist_elems;

    while (right_idx < n) {
        int32_t rval = vals[right_idx];
        dist_elems[rval] += 1;
        
        while (dist_elems.size() > d_elems) {
            int32_t lval = vals[left_idx];
            dist_elems[lval] -= 1;
            if (dist_elems[lval] == 0) {
                dist_elems.erase(lval);
            }
            left_idx++;
        }
        count += right_idx - left_idx + 1;
        right_idx++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;
    cout << count << endl;
}

