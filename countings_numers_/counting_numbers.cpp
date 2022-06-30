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
    int prev = num % 10;
    long long curr = num / 10;
    while (curr) {
        int curr2 = curr % 10;
        if (curr2 == prev) {
            return false;
        }
        prev = curr2;
        curr /= 10;
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