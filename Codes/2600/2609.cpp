#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    else return gcd(b % a, a);
}

int main() {
    int a, b, g;
    scanf("%d %d", &a, &b);
    g = gcd(a, b);
    printf("%d\n%d", g, a * b / g);
    return 0;
}
