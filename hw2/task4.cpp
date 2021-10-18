#include <iostream>

using namespace std;

int sum(int a, int b) {
    int s = a ^ b;
    int c = a & b;

    return c > 0 ? sum(s, c << 1) : s;
}

int main() {
    int a, b;

    cout << "Enter a and b, which you want to sum up:";
    cin >> a >> b;

    cout << "a+b=" << sum(a, b);
}