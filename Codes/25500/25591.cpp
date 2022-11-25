#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    a = 100 - a, b = 100 - b;
    int c = 100 - (a + b);
    int d = a * b;
    int q = d / 100;
    int r = d % 100;

    printf("%d %d %d %d %d %d\n%d %d", a, b, c, d, q, r, c + q, r);
    return 0;
}
