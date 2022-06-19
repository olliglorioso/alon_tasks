#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
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
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int totaliters = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i-1]) {
            totaliters += 1;
        }
    }
    cout << totaliters << endl;
}