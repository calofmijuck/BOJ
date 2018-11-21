#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, input;
    scanf("%d", &n);
    long long ans = 0;
    n *= n;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &input);
        ans += input;
    }
    printf("%lld", ans);
    return 0;
}
