# 3. Структури за управление. Графично представяне. Условен оператор (част 1)
**Задача 1.** Съставете С++ конзолна програма, чрез която да преобразувате числата от десетична бройна система в римска до най-голямото римско число (3999).

```c++
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
```

**Задача 2.** Съставете С++ конзолна програма, чрез която да преобразувате числата от римско число (1 до 3999) в десетична бройна система.

```c++
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
```

**Задача 3.** Съставете С++ конзолна програма, чрез която да изведете на екрана дали дадено реално число принадлежи на интервал дефиниран от програмиста с константни начало и край [MIN, MAX]. Използвайте дефиниране на константи чрез директиви.

```c++
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
```

**Задача 4.** Съставете С++ конзолна програма, чрез която да изведете на екрана всяка цифра на въведено от потребителя произволно цяло число.

```c++
#include "iostream"
#include "list"

using namespace std;

int main() {
    u_int number;

    cout << "Enter a number: ";
    cin >> number;

    list<u_short> digits;

    while(number > 0) {
        digits.push_front(number % 10);
        number /= 10;
    }

    for (const auto &item : digits) {
        cout << item << endl;
    }
}
```

**Задача 5.** Да се проучи как работи и за какво се използва функцията `rand()`. Съставете изрази, включващи извикване на тази функция, за да можете да генерирате псевдо сучайно цяло число в посочен от потребителя интервал. След което допълнете функционалността на програмата като отпечатате цифрите на така генерираното число (всяка на нов ред), само ако числото има най-много 3 цифри.

```c++
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
```

**Задача 6.**  Да се проучи как функцията `rand()` може да генерира случайни числа. Съставете израз, чрез който да можете да генерирате случайно реално число в зададен интервал.

```c++
#include "iostream"

using namespace std;

int main() {
    float start_range;
    float end_range;

    do {
        cout << "Interval for random number: ";
        cin >> start_range >> end_range;
    } while (start_range >= end_range);

    float real = (rand() % (end_range - start_range) + start_range) + rand();

    cout << real;
}
```