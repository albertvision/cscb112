#include "iostream"

using namespace std;

unsigned int swap_bits(int number, unsigned int pos1, unsigned int pos2, unsigned int bits_count) {
    unsigned int pos1_bits = (number >> pos1) & ((1U << bits_count) - 1);
    unsigned int pos2_bits = (number >> pos2) & ((1U << bits_count) - 1);

    unsigned int mask = pos1_bits ^ pos2_bits;
    mask = (mask << pos1) | (mask << pos2);

    return number ^ mask;
}

int main() {
    int x;
    unsigned int pos1, pos2, n;

    cout << "Enter x, pos1, pos2, and n: ";
    cin >> x >> pos1 >> pos2 >> n;

    cout << swap_bits(x, pos1, pos2, n);
}