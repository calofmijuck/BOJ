#include <iostream>
using namespace std;

int counter[10];

void count_digits(int number) {
    while (number > 0) {
        int digit = number % 10;
        counter[digit]++;

        number /= 10;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int product = a * b * c;
    count_digits(product);

    for (int i = 0; i < 10; ++i) {
        cout << counter[i] << '\n';
    }
    return 0;
}
