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
        times.push_back(make_pair(start_time, end_time));
    }

    sort (times.begin(), times.end());
    // Get the shortest movies for each start time.
    vector<pair<int, int>> movie_times;
    movie_times.push_back(times[0]);

    for (int i = 1; i < times.size(); i++) {
        int n = movie_times.size();
        if ((times[i].first == movie_times[n - 1].first) && ((times[i].second - times[i].first) < (movie_times[n - 1].second - movie_times[n - 1].first))) {
            movie_times[n - 1] = times[i];
        } else {
            movie_times.push_back(times[i]);
        }

    }
    
    int watched_movies = 0;
    int current_time = 0;
    for (int i = 0; i < times.size(); i++) {
        if (times[i].first >= current_time) {
            watched_movies++;
            current_time = times[i].second;
        }
    }
    cout << watched_movies << endl;
}