#include <bits/stdc++.h>
using namespace std;

int fib[45] = {1, 0, 1, 1};

int main() {
    int t, n;
    scanf("%d", &t);
    for(int i = 2; i <= 45; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    while(t--) {
        scanf("%d", &n);
        printf("%d %d\n", fib[n], fib[n + 1]);
    }
    return 0;
}
