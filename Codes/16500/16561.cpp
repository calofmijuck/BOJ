#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    n /= 3;
    printf("%lld", (long long) (n - 1) * (n - 2) / 2);
    return 0;
}
