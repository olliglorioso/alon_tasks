#include <string>
#include <iterator>
#include <vector>
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
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int moves_amount = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] < a[i - 1]) {
            int am = a[i - 1] - a[i];
            a[i] += am;
            moves_amount += am;
        }
    }
    cout << moves_amount;
}