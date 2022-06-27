#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <chrono>
#include <queue>
#include <tuple>
using namespace std;

queue<int32_t> q;
bool isOver = false;
int32_t originalK;
set<int> circle;

int32_t print_every_second(int32_t k) {
    if (q.size() == 0) {
        return 0;
    }

    for (int32_t i = 1; i <= k; i++) {
        int32_t fronttieri = q.front();
        q.pop();
        q.push(fronttieri);
    }
    int32_t front = q.front();
    q.pop();
    cout << front << " ";
    
    print_every_second(k);
}

int print_every_second_k_is_bigger(int k, int x) {
    if (circle.size() == 0) {
        return 0;
    }
    x = (x + k) % circle.size();
    cout << x << " ";
    circle.erase(x);
    // for (int i = 1; i <= s; i++) {
    //     int fronttieri = circle.front();
    //     circle.pop();
    //     circle.push(fronttieri);
    // }
    // int front = circle.front();
    // q.pop();
    // cout << front << " ";
    
    print_every_second_k_is_bigger(k, x);
}

int main() {
    int32_t n, k;
    cin >> n >> k;
    originalK = k;

    
    if (k > n) {
        for (int32_t i = 1; i <= n; i++) {
            circle.insert(i);
        }
        print_every_second_k_is_bigger(k, 0);
    } else {
        for (int32_t i = 1; i <= n; i++) {
            q.push(i);
        }
        print_every_second(k);
    }

    
    return 0;
}