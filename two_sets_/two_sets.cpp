#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
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
    vector<int64_t> a, b;
    cin >> n;
    // Lukujen 1...n summa voidaan laskea kaavalla (n*(n+1))/2. Jos summa on pariton, vastaus on NO.
    int64_t sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << "NO";
        return 0;
    }
    int64_t answer = sum / 2;
    for (int64_t i = 1; i <= n; i++) {
        
        if (i <= answer) {
            a.push_back(i);
            answer -= i;
        } else {
            b.push_back(i);
        }
    }

    cout << "YES\n";
    cout << a.size() << "\n";
    for_each(a.begin(), a.end(),
             [](const auto & elem){
                cout<<elem<<" "; 
        });
    cout << "\n";
    cout << b.size() << "\n";
    for_each(b.begin(), b.end(),
             [](const auto & elem){
                cout<<elem<<" "; 
        });
}