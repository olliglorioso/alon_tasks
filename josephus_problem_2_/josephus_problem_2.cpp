#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <chrono>
#include <queue>
#include <tuple>
using namespace std;

queue<int> q;

int print_every_second(int k) {
    if (q.size() == 0) {
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        int fronttieri = q.front();
        q.pop();
        q.push(fronttieri);
    }
    int front = q.front();
    q.pop();
    cout << front << " ";
    
    
    print_every_second(k);
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    print_every_second(k);
    return 0;
}