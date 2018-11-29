#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", n == 1 ? 0 : (++n >> 1));
    return 0;
}
