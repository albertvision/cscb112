#include "iostream"

using namespace std;

int main() {
    int a, b;

    cout << "Enter a and b: ";
    cin >> a >> b;

    int mask = a ^ b;
    a = a ^ mask;
    b = b ^ mask;

    cout << a << endl << b;
}