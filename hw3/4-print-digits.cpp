#include "iostream"
#include "list"

using namespace std;

int main() {
    u_int number;

    cout << "Enter a number: ";
    cin >> number;

    list<u_short> digits;

    while(number > 0) {
        digits.push_front(number % 10);
        number /= 10;
    }

    for (const auto &item : digits) {
        cout << item << endl;
    }
}