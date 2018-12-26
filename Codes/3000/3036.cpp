#include <bits/stdc++.h>
using namespace std;

int ring[101];

int gcd(int a, int b) {
    if(!a) return b;
    else return gcd(b % a, a);
}

int main() {
    int n, g;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", ring + i);
    for(int i = 1; i < n; ++i) {
        g = gcd(ring[0], ring[i]);
        printf("%d/%d\n", ring[0] / g, ring[i] / g);
    }
    return 0;
}
