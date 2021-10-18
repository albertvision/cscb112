#include "iostream"

using namespace std;

void sort(unsigned int *numbers, unsigned int count) {
    for (int i = 0; i < count; ++i) {
        for (int j = 1; j < count - i; ++j) {
            if (numbers[j - 1] > numbers[j]) {
                numbers[j - 1] += numbers[j];
                numbers[j] = numbers[j - 1] - numbers[j];
                numbers[j - 1] -= numbers[j];
            }
        }
    }
}

unsigned int get_missing_item(const unsigned int *numbers, unsigned int count) {
    unsigned int diff;

    for (int i = 1; i < count; i++) {
        diff = numbers[i] - 1;

        if (diff != numbers[i - 1]) {
            return diff;
        }
    }

    throw invalid_argument("no missing item.");
}

int main() {
    unsigned int numbers[] = {1, 3, 4, 5, 6, 8, 2};
    auto count = sizeof(numbers) / sizeof(unsigned int);

    sort(numbers, count);

    cout << get_missing_item(numbers, sizeof(numbers) / sizeof(unsigned int));
}