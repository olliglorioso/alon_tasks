#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int moves = 0;

int cut_into_squares(int height, int width) {
    if (height == width) {
        return moves;
    } else if (height > width) {
        moves++;
        cut_into_squares(height - width, width);
    } else if (width > height) {
        moves++;
        cut_into_squares(height, width - height);
    }
}

int main () {
    int leveys, korkeus;
    cin >> leveys >> korkeus;

    int moveAmount = cut_into_squares(leveys, korkeus);
    cout << moveAmount << endl;
}