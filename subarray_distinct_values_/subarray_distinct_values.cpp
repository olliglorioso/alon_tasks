#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
// #include <chrono>
using namespace std;
// using namespace std::chrono;

int main() {
    // auto start = high_resolution_clock::now();
    int64_t n, d_elems; 
    cin >> n >> d_elems;
    vector<int64_t> vals;
    for (int64_t i = 0; i < n; i++) {
        int64_t a;
        cin >> a;
        vals.push_back(a);
    }
    int64_t count = 0;
    int64_t left_idx = 0;
    int64_t right_idx = 0;
    map<int64_t, int64_t> dist_elems;

    while (right_idx < n) {
        int64_t rval = vals[right_idx];
        dist_elems[rval] += 1;
        
        while (dist_elems.size() > d_elems) {
            int64_t lval = vals[left_idx];
            dist_elems[lval] -= 1;
            if (dist_elems[lval] == 0) {
                dist_elems.erase(lval);
            }
            left_idx++;
        }
        count += right_idx - left_idx + 1;
        right_idx++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    // cout << duration.count() << endl;
    cout << count << endl;
}

