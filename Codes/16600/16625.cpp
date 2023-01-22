#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    }

    if (y == 0) {
        return x;
    } else {
        return gcd(x % y, y);
    }
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    int p, q, seconds;
    scanf("%d %d %d", &p, &q, &seconds);

    int l = lcm(p, q);
    if (seconds >= l) {
        puts("yes");
    } else {
        puts("no");
    }
    return 0;
}
