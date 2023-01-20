#include <bits/stdc++.h>
using namespace std;

int main() {
    int required[3];
    double sum = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &required[i]);
        sum += required[i];
    }

    sum /= 2;

    double precipitation[3];
    bool positive = true;
    for (int i = 0; i < 3; ++i) {
        precipitation[i] = sum - required[2 - i];
        positive &= (precipitation[i] > 0);
    }

    if (positive) {
        printf("1\n");
        for (int i = 0; i < 3; ++i) {
            printf("%.1lf ", precipitation[i]);
        }
    } else {
        printf("-1");
    }
    return 0;
}
