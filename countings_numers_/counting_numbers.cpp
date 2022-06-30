#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_vector(vector<long long> vec) {
    cout << endl;
    cout << "vector elements : ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

bool is_good (long long num) {
    long long numb = num;
    vector<long long> numbs;
    while (numb >= 10) {
        int a = numb % 10;
        numb = numb / 10;
        numbs.push_back(a);
    }
    numbs.push_back(numb);
    if (numbs.size() == 1) {
        return true;
    }
    
    for(int i = 0; i < numbs.size(); i++) {
        if (i == 0) {
            if (numbs[i] == numbs[i + 1]) {
                return false;
            } else {
                continue;
            }
        }
        if (i == (numbs.size() - 1)) {
            if (numbs[i - 1] == numbs[i]) {
                return false;
            } else {
                continue;
            }
        }
        if (numbs[i] == numbs[i + 1] || numbs[i] == numbs[i - 1]) {
            return false;
        }
    }
    return true;
}

long long count_numbers(long long num1, long long num2) {
    long long sum = 0;
    for (long long i = num1; i <= num2; i++) {
        bool isgoood = is_good(i);
        if (isgoood) {
            sum += 1;
        }
    }
    return sum;
}

int main () {
    long long num1, num2;
    cin >> num1 >> num2;
    long long counted = count_numbers(num1, num2);
    cout << counted << endl;
}