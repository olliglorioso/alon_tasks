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
        size_t index = distance(b.begin(), find(b.begin(), b.end(), prev_val));
        // if there is no previous value, then we add it to the end of the vector
        if (index == b.size()) {
            b.push_back(a[i]);
        }
        // if there is a previous value, then we insert it at the right position
        else {
            b[index]++;
        }
    }
    cout << b.size() << endl;
}