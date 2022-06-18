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
    int64_t n;
    cin >> n;
    vector<int64_t> a;
    for (int64_t i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int64_t moves_amount = 0;
    int64_t biggest_num = 0;
    while (true)
    {
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] == biggest_num + 1) {
                biggest_num = a[i];
                a.erase(a.begin() + i);
            }
        }
        moves_amount += 1;
        if (a.size() == 0) {
            break;
        }
    }   
    
    
    cout << moves_amount - 1;
}