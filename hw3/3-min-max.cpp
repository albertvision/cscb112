#include <iostream>

#define MIN 13
#define MAX 2933

using namespace std;

int main() {
    int number;

    cout << "Enter a number [" << MIN << ", " << MAX << "]: ";
    cin >> number;

    if(number >= MIN && number <= MAX) {
        cout << "Number's fine.";

        return 0;
    }

    cout << "Out of range.";
    return 1;
}
