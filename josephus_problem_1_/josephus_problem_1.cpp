#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <map>
#include <queue>
using namespace std;

queue<int> q;

void print_vector(vector<int64_t> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int64_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int print_every_second() {
    if (q.size() == 0) {
        return 0;
    }
    int front2 = q.front();
    q.pop();
    q.push(front2);
    int front = q.front();
    q.pop();
    cout << front << " ";
    
    
    print_every_second();
}
 
int main() {
    int n;
    cin >> n;
    
    for (int64_t i = 1; i <= n; i++) {
        q.push(i);
    }

    print_every_second();
    cout << endl;
}