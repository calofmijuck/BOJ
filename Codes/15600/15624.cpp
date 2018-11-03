#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0) {
        printf("0");
    } else if(n <= 2) {
        printf("1");
    } else {
        int a0 = 0, a1 = 1, a2 = a0 + a1, tmp;
        for(int i = 2; i < n; i++) {
            tmp = (a1 + a2) % MOD;
            a0 = a1;
            a1 = a2;
            a2 = tmp;
        }
        printf("%d", tmp);
    }
}
