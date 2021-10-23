#include "iostream"

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
    float real = (rand() % (end_range - start_range) + start_range) + rand();

    cout << real;
}
