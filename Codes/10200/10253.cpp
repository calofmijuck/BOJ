#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    int x = (b + a - 1) / a;
    if(a * x - b == 0) return x;
    else return solve(a * x - b, b * x);
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", solve(a, b));
    }
    return 0;
}
