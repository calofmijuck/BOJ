#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, ans;
    scanf("%d %d %d", &a, &b, &n);
    a %= b;
    for(int i = 0; i < n; ++i) {
        a *= 10;
        ans = a / b;
        a %= b;
    }
    printf("%d", ans);
    return 0;
}
