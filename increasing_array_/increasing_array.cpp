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
    int one_move = false;
    while (true)
    {
        for (size_t i = 0; i < a.size(); i++){
            if (a[i] < a[i - 1])
            {
                a[i] += 1;
                one_move = true;
                moves_amount += 1;
            }
        }
        if (one_move != true)
        {
            break;
        }
        one_move = false;
    }
    cout << moves_amount;
}