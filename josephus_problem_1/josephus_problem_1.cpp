#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <map>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    for (int64_t i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
    for (int64_t i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    return 0;
}