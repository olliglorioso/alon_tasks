#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <chrono>
#include <queue>
using namespace std;
using namespace std::chrono;

void print_vectors(vector<vector<int>> vec) {
    cout << "vector elements: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i][0] << " and " << vec[i][1] << endl;
    }
}

void print_vector(vector<int> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int n_customers; 
    cin >> n_customers; 
    vector<pair<int, int>> customers;
    
    
    for (int i = 0; i < n_customers;  i++) {
        int res_start, res_end;
        cin >> res_start >> res_end;
        // 1 for departure and 0 for arrival.
        customers.push_back(make_pair(res_start, 0));
        customers.push_back(make_pair(res_end, 1));
    }
    sort(customers.begin(), customers.end());
    // rooms[n] == 0 if room is free. (room_number: ())
    map<int, int> rooms;
    int current_time = 0;
    int k = 1;
    int rooms_needed = 0;
    vector<int> rooms_reserved;

    for (int i = 0; i < n_customers; i++) {
        if (customers[i].second == 0) {
            bool room_was_free = false;
            for (int s = 1; s <= rooms.size(); s++) {
                if (rooms[s] == 0) {
                    rooms[s] = 1;
                    rooms_reserved.push_back(s);
                    break;
                }
            }
            if (room_was_free == false) {
                rooms[k] = 1;
                rooms_reserved.push_back(k);
                rooms_needed++;
                k++;
            }
        } else if (customers[i].second == 1) {
            for (int v = 1; v <= rooms.size(); v++) {
                // if (rooms[v]=);
            }
        }
    }

    print_vector(rooms_reserved);
    cout << rooms_needed << endl;
}

