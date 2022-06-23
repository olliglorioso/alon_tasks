#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <map>
using namespace std;
 
int main() {
    int movie_amount;
    cin >> movie_amount;
    vector<pair<int, int>> times;
 
    for (int i = 1; i <= movie_amount; i++) {
        // Get two numbers in one line as input
        int start_time, end_time;
        cin >> start_time >> end_time;
        times.push_back(make_pair(end_time, start_time));
    }
 
    sort (times.begin(), times.end());
    
    int watched_movies = 0;
    int current_time = 0;
    for (int i = 0; i < movie_amount; i++) {
        if (times[i].second >= current_time) {
            watched_movies++;
            current_time = times[i].first;
        }
    }

    cout << watched_movies << endl;
}