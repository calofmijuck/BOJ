#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 1;
    for(int i = 2; i <= n; ++i) ans *= i;
    printf("%d", ans);
    return 0;
}
