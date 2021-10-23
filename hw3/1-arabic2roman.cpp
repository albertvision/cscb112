#include "iostream"
#include "list"

using namespace std;

/*
 * Макар енумерацията да е напълно ненужна в тази имплементация,
 * реших да я използвам, защото е част от новата лекция.
 *
 * Иначе щях да поставя нейните стойностности директно в списъка от двойки `roman_chars`.
 */
enum roman {
    M = 1000,
    CM = 900,
    D = 500,
    CD = 400,
    C = 100,
    XC = 90,
    L = 50,
    XL = 40,
    X = 10,
    IX = 9,
    V = 5,
    IV = 4,
    I = 1
};

list<pair<roman, string>> roman_chars = {
        {M,  "M"},
        {CM, "CM"},
        {D,  "D"},
        {CD, "CD"},
        {C,  "C"},
        {XC, "XC"},
        {L,  "L"},
        {XL, "XL"},
        {X,  "X"},
        {IX, "IX"},
        {V,  "V"},
        {IV, "IV"},
        {I,  "I"},
};

int main() {
    unsigned short arabic;

    do {
        cout << "Enter arabic integer ([1-3999]): ";
        cin >> arabic;
    } while (arabic < 1 || arabic > 3999);

    cout  << "Roman numeral: ";

    while (arabic > 0) {
        for (const auto& [roman_num, roman_char] : roman_chars) {
            if (arabic >= roman_num) {
                cout << roman_char;
                arabic -= roman_num;

                break;
            }
        }
    }

}