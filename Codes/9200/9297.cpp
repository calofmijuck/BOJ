#include <bits/stdc++.h>
using namespace std;

void reduce_fraction(int tc) {
    printf("Case %d: ", tc);

    int denominator, numerator;
    scanf("%d %d", &numerator, &denominator);

    int integer = numerator / denominator;
    int fraction = numerator % denominator;
    if (integer == 0) {
        if (fraction == 0) {
            printf("0\n");
            return;
        }

        printf("%d/%d\n", fraction, denominator);
        return;
    }

    if (fraction == 0) {
        printf("%d\n", integer);
        return;
    }

    printf("%d %d/%d\n", integer, fraction, denominator);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        reduce_fraction(i);
    }
    return 0;
}
