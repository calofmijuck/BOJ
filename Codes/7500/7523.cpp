#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        printf("Scenario #%d:\n%lld\n\n", i + 1, (n + m) * (m - n + 1) / 2);
    }
    return 0;
}
