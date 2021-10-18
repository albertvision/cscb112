#include "iostream"
#include "map"
#include "list"

using namespace std;

int sum(int a, int b) {
    int s = a ^ b;
    int c = a & b;

    return c > 0 ? sum(s, c << 1) : s;
}

auto get_odd_number_occurrences(int numbers[], int count) {
    map<int, int> occurrences;
    list<int> odds;

    for (int i = 0; i < count; ++i) {
        occurrences[numbers[i]] = sum(occurrences[numbers[i]], 1);
    }

    for (const auto &[number, count] : occurrences) {
        if ((count & 1) == 1) {
            odds.push_back(number);
        }
    }

    return odds;
}

int main() {
    short count;

    cout << "How many numbers you will enter: ";
    cin >> count;

    int numbers[count];

    for (short i = 0; i < count; ++i) {
        cout << "Number " << (i+1) << ":" << endl;
        cin >> numbers[i];
    }

    auto odds = get_odd_number_occurrences(numbers, count);

    cout << "Odd occurrences have: ";

    for (const auto &item : odds) {
        cout << item << endl;
    }
}