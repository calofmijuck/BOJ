#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[8], s[6];

ll dsq(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 8; ++i) scanf("%lld", p + i);
        s[0] = dsq(p[0], p[1], p[2], p[3]);
        s[1] = dsq(p[0], p[1], p[4], p[5]);
        s[2] = dsq(p[0], p[1], p[6], p[7]);
        s[3] = dsq(p[2], p[3], p[4], p[5]);
        s[4] = dsq(p[2], p[3], p[6], p[7]);
        s[5] = dsq(p[4], p[5], p[6], p[7]);
        sort(s, s + 6);
        if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5] && s[0] * 2 == s[4]) puts("1");
        else puts("0");
    }
    return 0;
}
