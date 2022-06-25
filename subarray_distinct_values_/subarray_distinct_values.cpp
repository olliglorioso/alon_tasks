#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <unordered_map>
using namespace std;

void print_vectors(vector<vector<int64_t>> vec) {
    cout << "vector elements: " << endl;
    for (int64_t i = 0; i < vec.size(); i++) {
        cout << vec[i][0] << " and " << vec[i][1] << endl;
    }
}

void print_vector(vector<int64_t> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int64_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
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
    unordered_map<int64_t, int64_t> dist_elems;

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

    cout << count << endl;
}

