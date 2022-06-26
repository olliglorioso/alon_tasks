#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <chrono>
#include <queue>
#include <tuple>
using namespace std;

queue<int32_t> q;
bool isOver = false;

int32_t print_every_second(int32_t k, int32_t curLen) {
    if (q.size() == 0) {
        return 0;
    }
    int32_t s;
    if (isOver == true) {
        s = k % curLen;
        curLen -= 1;
    }

    for (int32_t i = 1; i <= s; i++) {
        int32_t fronttieri = q.front();
        q.pop();
        q.push(fronttieri);
    }
    int32_t front = q.front();
    q.pop();
    cout << front << " ";
    
    print_every_second(k, curLen);
}

int main() {
    int32_t n, k;
    cin >> n >> k;

    for (int32_t i = 1; i <= n; i++) {
        q.push(i);
    }
    if (k > n) {
        isOver = true;
    }

    print_every_second(k, n);
    return 0;
}