#include <bits/stdc++.h>
using namespace std;

int main() {
    long long d1, d2, k;
    scanf("%lld %lld %lld", &k, &d1, &d2);
    double t = (d1 - d2) / 2.0;
    printf("%lf", k * k - t * t);
    return 0;
}
