#include "iostream"
#include "list"

using namespace std;

int main() {
    int start_range;
    int end_range;

    do {
        cout << "Interval for random int: ";
        cin >> start_range >> end_range;
    } while (start_range >= end_range);

    srand(time(nullptr));

    // 5. pseudo-random int
    int integer = (int) (rand() % (end_range - start_range) + start_range);

    if (integer < 1000) {
        list<u_short> digits;
        while(integer > 0) {
            digits.push_front(integer % 10);
            integer /= 10;
        }

        for (const auto &item : digits) {
            cout << item << endl;
        }
    }
}
