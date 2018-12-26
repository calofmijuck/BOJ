#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    else return gcd(b % a, a);
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a * b / gcd(a, b));
    }
    return 0;
}
