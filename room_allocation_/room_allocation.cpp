#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <chrono>
#include <queue>
#include <tuple>
using namespace std;
using namespace std::chrono;

void print_vectors(vector<tuple<int, int, int>> vec) {
    cout << "vector elements: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << get<0>(vec[i]) << get<1>(vec[i]) << get<2>(vec[i]) << endl;
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
    vector<tuple<int, int, int>> customers;   // First one is relevant time (arrival, departure), second one is 0 if arrival and 1 if departure, and third one is customer number.
    
    int custNumber = 1;
    
    // Collect the customer information via cin.
    for (int i = 0; i < n_customers;  i++) {
        int res_start, res_end;
        cin >> res_start >> res_end;
        customers.push_back(make_tuple(res_start, 0, custNumber));
        customers.push_back(make_tuple(res_end, 1, custNumber));
        custNumber++;
    }

    sort(customers.begin(), customers.end());
    
    int current_time = 0;
    int rooms_needed = 0;
    vector<int> rooms_reserved;
    queue<int> freeRooms;
    

    for (int i = 0; i < customers.size(); i++) {
        int custNro = get<2>(customers[i]);
        if (get<1>(customers[i]) == 0) {
            if (freeRooms.size() > 0) {
                int room_to_reserve = freeRooms.front();
                freeRooms.pop();
                rooms_reserved.push_back(room_to_reserve);
            } else {
                rooms_reserved.push_back(custNro);
                rooms_needed++;
            }
        } if (get<1>(customers[i]) == 1) {
            freeRooms.push(custNro);
        }
    }

    print_vector(rooms_reserved);
    cout << rooms_needed << endl;
}

