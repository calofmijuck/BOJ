#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    double ans = 1.0 * x / (c - x);
    ans = ans * y / (a - y);
    ans = b / (1 + ans);
    printf("%.8lf", ans);
    return 0;
}
