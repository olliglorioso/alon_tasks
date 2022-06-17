#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>
using namespace std;

int main() {
    // int64_t size_of_array; 
    // cin >> size_of_array;

    int** a = new int*[1];
    int row = -1; 
    int n;
    while (cin >> n) {
        row++;
        for (int col = 0; col < n; col++)
            cin >> a[row][col];
    }

    cout << a;

    // cout << 5;
}