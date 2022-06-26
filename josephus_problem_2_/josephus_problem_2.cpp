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

int print_every_second() {
    if (q.size() == 0) {
        return 0;
    }
    int front2 = q.front();
    q.pop();
    q.push(front2);
    int front3 = q.front();
    q.pop();
    q.push(front3);
    int front = q.front();
    q.pop();
    cout << front << " ";
    
    
    print_every_second();
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    print_every_second();
    return 0;
}