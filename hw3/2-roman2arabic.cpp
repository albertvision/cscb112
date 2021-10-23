#include "iostream"
#include "map"

using namespace std;

map<char, unsigned short> romans = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
};

int main() {
    string roman;
    cout << "Enter roman numeral: ";
    cin >> roman;

    unsigned short arabic(0);

    for (int i = 0; i < roman.size(); ++i) {
        arabic += romans[roman[i]];

        if (i > 0 && romans[roman[i]] > romans[roman[i - 1]]) {
            arabic += - 2 * romans[roman[i - 1]];
        }
    }

    cout << arabic;
}