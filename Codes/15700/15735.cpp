#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", (long long) floor(n * (n + 2) * (2 * n + 1) / 8));
    return 0;
}
