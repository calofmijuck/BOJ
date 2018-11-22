#include <bits/stdc++.h>
using namespace std;

int gen(int i) {
    int res = i;
    while(i > 0) {
        res = res + i % 10;
        i /= 10;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int t = max(1, n - 54);
    for(int i = t; i <= n; ++i) {
        int x = gen(i);
        if(x == n) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
    return 0;
}
