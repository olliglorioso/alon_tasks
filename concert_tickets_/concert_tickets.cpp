#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <map>
#include <queue>
using namespace std;



void print_vector(vector<int> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int closest(std::vector<int> const& vec, int value) {
    auto const it = upper_bound(vec.begin(), vec.end(), value);
    int res = it - vec.begin();
    if (res == 0) {
        return -1;
    } else {
        return it - vec.begin();
    }
}

int main() {
    int n_cust, n_ticket;
    cin >> n_ticket >> n_cust;

    vector<int> customers;
    vector<int> tickets;
    
    for (int i = 1; i <= n_ticket; i++) {
        int a;
        cin >> a;
        tickets.push_back(a);
    }

    for (int i = 1; i <= n_cust; i++) {
        int a;
        cin >> a;
        customers.push_back(a);
    }

    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < n_cust; i++) {
        int res = closest(tickets, customers[i]);
        if (res == -1) {
            cout << -1 << endl;
        } else {
            cout << tickets[res - 1] << endl;
            tickets.erase(tickets.begin() + res - 1);
        }
    }
}