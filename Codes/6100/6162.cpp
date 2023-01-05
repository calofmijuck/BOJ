#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Data Set %d:\n", i);

        int expected, actual;
        scanf("%d %d", &expected, &actual);

        double rate = double(expected) / actual;
        if (rate <= 1) {
            printf("no ");
        } else {
            while (rate > 5) {
                printf("mega ");
                rate /= 5;
            }
        }

        printf("drought\n\n");
    }
    return 0;
}
