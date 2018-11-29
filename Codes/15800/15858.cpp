#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    long double res = (long double) a / c;
    printf("%.10Lf", res * (long double) b);
    return 0;
}
