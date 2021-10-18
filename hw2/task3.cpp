#include "iostream"

using namespace std;

int main() {
    int a, b;

    cout << "Enter a and b: ";
    cin >> a >> b;

    a += b;
    cout << a << endl;

    a /= b;
    cout << a << endl;

    a -= b;
    cout << a << endl;

    a *= b;
    cout << a << endl;

    a %= b;
    cout << a << endl;
}