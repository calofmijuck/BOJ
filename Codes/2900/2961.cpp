#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll sour[11], bitter[11], ans = 1000000000;

void solve(ll currs, ll currb, int k) {
    if(k >= n) return;
    solve(currs, currb, k + 1);
    currs *= sour[k];
    currb += bitter[k];
    if(abs(currs - currb) < ans) ans = abs(currs - currb);
    solve(currs, currb, k + 1);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld", sour + i, bitter + i);
    }
    solve(1, 0, 0);
    printf("%lld", ans);
    return 0;
}
