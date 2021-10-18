#include <sstream>
#include "iostream"
#include "fstream"
#include "cmath"
#include "list"

using namespace std;

list<unsigned int> prime_nums;

unsigned short get_digit(int number, int position) {
    int power_int = (int) pow(10, position);
    int power_mod = (int) pow(10, position-1);

    if (number / power_mod < 1) {
        throw invalid_argument("Position is too high.");
    }

    return (number % power_int) / power_mod;
}

unsigned short get_highest_digit(int number) {
    short highest(0);
    short last;

    while(number > 0) {
        last = (short) get_digit(number, 1);

        if (last > highest) {
            highest = last;
        }

        number /= 10;
    }

    return highest;
}

unsigned short get_digits_sum(int number) {
    unsigned short sum (0);

    while(number > 0) {
        sum += get_digit(number, 1);
        number /= 10;
    }

    return sum;
}

auto get_canonical_form(int number) {
    list<unsigned int> dividers;

    while (number > 1) {
        for (const auto &prime : prime_nums) {
            if (number % prime == 0) {
                dividers.push_back(prime);
                number /= (int) prime;

                break;
            }
        }
    }

    return dividers;
}

auto get_dividers_count(list<unsigned int> dividers) {
    unsigned int dividers_count(1);
    unsigned int previous_divider = dividers.front();
    unsigned int previous_divider_count(0);

    for (const auto &divider : dividers) {
        if (divider != previous_divider) {
            dividers_count *= previous_divider_count + 1;

            previous_divider_count = 1;
        } else {
            previous_divider_count++;
        }

        previous_divider = divider;
    }
    dividers_count *= previous_divider_count + 1;

    return dividers_count;
}

void read_prime_nums() {
    string last_line;
    int prime;

    ifstream file("../hw2/primenums.txt");

    while (getline(file, last_line)) {
        stringstream line_stream(last_line);

        line_stream >> prime;
        prime_nums.push_back(prime);
    }
}

int main() {
    int number;
    int n;

    read_prime_nums();

    cout << "Enter a number, and position of the digit to return: ";
    cin >> number >> n;

    auto digit = get_digit(number, n);
    auto digits_sum = get_digits_sum(number);

    cout << "1. nth digit:" << digit << endl
        << "2. highest digit: " << get_highest_digit(number) << endl
        << "3. sum of digit: " << digits_sum << endl
        << "4. nth digit even: " << (digit % 2 == 0) << endl
        << "5. digits sum even: " << (digits_sum % 2 == 0) << endl
        << "6. number of dividers: " << get_dividers_count(get_canonical_form(number));
}