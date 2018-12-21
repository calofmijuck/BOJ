#include <bits/stdc++.h>
using namespace std;

long long fib[100] = {0, 1, 1};

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("%lld", fib[n]);
    return 0;
}
