#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    while(a != b) {
        if(a > b) a >>= 1;
        else if(a < b) b >>= 1;
    }
    return a;
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        printf("%d0\n", solve(a, b));
    }
    return 0;
}
