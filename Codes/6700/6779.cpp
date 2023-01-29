#include <bits/stdc++.h>
using namespace std;

int coefficients[4] = { -6, 0, 2, 1 };

int evaluate(int x) {
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        result += coefficients[i];
        result *= x;
    }
    return result;
}

int main() {
    int humidity, hour_limit;
    scanf("%d %d", &humidity, &hour_limit);

    coefficients[1] = humidity;
    for (int i = 1; i <= hour_limit; ++i) {
        if (evaluate(i) <= 0) {
            printf("The balloon first touches ground at hour: %d", i);
            return 0;
        }
    }
    printf("The balloon does not touch ground in the given time.");
    return 0;
}
