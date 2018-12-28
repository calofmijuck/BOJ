#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int fib1 = 1, fib2 = 2, tmp = 3;
    if(n == 1) printf("1");
    else if(n == 2) printf("2");
    else {
        for(int i = 3; i <= n; ++i) {
            tmp = (fib1 + fib2) % 10;
            fib1 = fib2;
            fib2 = tmp;
        }
        printf("%d", fib2);
    }
    return 0;
}
