#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int solve(int l, int x, int y) {
    if(l == 1) return 1;
    int h = l >> 1, k = h * h;
    if(x < h && y < h) return solve(h, x, y);
    else if(x < h && y >= h) return k + solve(h, x, y - h);
    else if(x >= h && y < h) return 2 * k + solve(h, x - h, y);
    else return 3 * k + solve(h, x - h, y - h);
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", solve(1 << n, r, c) - 1);
    return 0;
}
