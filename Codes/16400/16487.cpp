#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, m;
    scanf("%d %d %d %d", &a, &b, &c, &m);
    double res = 1.0 * a * a * (b - m);
    res += c * c * m;
    res /= b;
    res -= m * (b - m);
    printf("%.8lf", res);
    return 0;
}
