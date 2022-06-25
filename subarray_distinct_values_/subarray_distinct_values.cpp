#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <unordered_map>
using namespace std;

void print_vectors(vector<vector<int>> vec) {
    cout << "vector elements: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i][0] << " and " << vec[i][1] << endl;
    }
}

void print_vector(vector<int> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, d_elems; 
    cin >> n >> d_elems;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vals.push_back(a);
    }
    int count = 0;
    int left_idx = 0;
    int right_idx = 0;
    unordered_map<int, int> dist_elems;

    while (right_idx < n) {
        int rval = vals[right_idx];
        dist_elems[rval] += 1;
        
        while (dist_elems.size() > d_elems) {
            int lval = vals[left_idx];
            dist_elems[lval]--;
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

