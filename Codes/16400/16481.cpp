#include <bits/stdc++.h>
using namespace std;

int main() {
    int r1, r2, r3;
    scanf("%d %d %d", &r1, &r2, &r3);
    double hsum = 1.0 / r1 + 1.0 / r2 + 1.0 / r3;
    printf("%.8lf", 1 / hsum);
    return 0;
}
