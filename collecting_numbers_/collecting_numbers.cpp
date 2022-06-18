#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a;
    for (int64_t i = 1; i <= n; i++) {
        int64_t x;
        cin >> x;
        a.push_back(x);
    }

    vector<int64_t> b = {0};
    for (size_t i = 0; i < a.size(); i++) {
        int64_t prev_val = a[i] - 1;
        if (count(b.begin(), b.end(), prev_val) != 0) {
            // find the index of prev_val
            size_t index = distance(b.begin(), find(b.begin(), b.end(), prev_val));
            b[index]++;
        } else {
            b.push_back(a[i]);
        }
    }
    cout << b.size() << endl;
}