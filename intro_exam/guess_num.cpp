#include <iostream>
#include <random>

using namespace std;

int main() {
    float start_range;
    float end_range;

    do {
        cout << "Interval for random int (separated by space): ";
        cin >> start_range >> end_range;
    } while (start_range >= end_range);

    // generate random int using Mersenne Twister
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<float> range(start_range, end_range);

    // keep 2 numbers after decimal
    auto generated_number = (float) (round(range(generator) * 100.0) / 100.0);

    cout << generated_number;

    // Attempts
    int tries = 0;
    float attempt;

    do {
        if (tries == 0) {
            cout << "Guess the number: ";
        } else {
            cout << "Number is " << (attempt < generated_number ? "higher" : "lower") << "! Try again: ";
        }

        tries++;
        cin >> attempt;
    } while(attempt != generated_number);

    cout << "You guessed the number on the " << tries << " try!";
}