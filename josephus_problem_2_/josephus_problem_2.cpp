#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <chrono>
#include <queue>
#include <tuple>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
queue<int> q;
bool isOver = false;
int originalK;
indexed_set que;
int n, k;

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
int rounds = 0;
int print_every_second_k_is_bigger(int x) {
    if (que.size() == 1) {
        cout << *que.begin();
        return 0;
    } 
    x = (k + x) % que.size();
    cout << "x on " << x << endl;
    cout << *que.find_by_order(x) << endl;
    que.erase(que.find_by_order(x));
    // for (int i = 1; i <= s; i++) {
    //     int fronttieri = que.front();
    //     que.pop();
    //     que.push(fronttieri);
    // }
    // int front = que.front();
    // q.pop();
    // cout << front << " ";
    rounds++;
    if (rounds < 5){
        print_every_second_k_is_bigger(x);
    }
    
}

int main() {
    
    cin >> n >> k;
    if (k > n) {
        for (int i = 1; i <= n; i++) {
            que.insert(i);
        }
        
        print_every_second_k_is_bigger(0);
    } else {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        print_every_second(k);
    }

    
    return 0;
}