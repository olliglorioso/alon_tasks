#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

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
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<int64_t> b = a;
    int64_t moves_amount = 0;
    int64_t biggest_num = 0;
    while (true)
    {
        a = b;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] == biggest_num + 1) {
                int num = a[i];
                biggest_num = num;
                b.erase(remove(b.begin(), b.end(), a[i]), b.end());
            }
        }
        // cout << biggest_num << " thast was biggest num, this is the list " << a << endl;
        if (a.size() == 0) {
            break;
        }
        // cout << a << " moves amount: " << moves_amount << endl;
        moves_amount += 1;
    }   
    
    
    cout << moves_amount;
}