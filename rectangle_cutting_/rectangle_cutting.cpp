#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;


long long cut_into_squares(long long height, long long width) {
    int values[height + 1][width + 1];

    for (int a = 1; a <= height; a++) {
        for (int b = 1; b <= width; b++) {
            if (a == b) {
                values[a][b] = 0;
            } else {
                int value = 100000;
                for (int i = 1; i < b; i++) {
                    value = min(value, values[a][b - i] + values[a][i] + 1);
                }
                for (int i = 1; i < a; i++) {
                    value = min(value, values[a - i][b] + values[i][b] + 1);
                }
                values[a][b] = value;
            }
        }
    }
    return values[height][width];
}

int main () {
    long long leveys, korkeus;
    cin >> leveys >> korkeus;

    long long moveAmount = cut_into_squares(leveys, korkeus);
    cout << moveAmount << endl;
} 