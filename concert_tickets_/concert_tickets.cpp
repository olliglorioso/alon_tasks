#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <set>
#include <chrono>
using namespace std;
using namespace std::chrono;


void print_vector(vector<int> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int n_cust, n_ticket;
    cin >> n_ticket >> n_cust;

    vector<int> customers;
    multiset<int, greater<int>> tickets;
    
    for (int i = 1; i <= n_ticket; i++) {
        int a;
        cin >> a;
        tickets.insert(a);
    }

    for (int i = 1; i <= n_cust; i++) {
        int a;
        cin >> a;
        customers.push_back(a);
    }
    for (int i = 0; i < n_cust; i++) {
        const int value = customers[i];
        auto it = tickets.lower_bound(value);
        if (it != tickets.end()) {
            auto loc = it--;
            cout << *loc << endl;
            tickets.erase(loc);

        } else {
            cout << -1 << endl;
        }
    }
}