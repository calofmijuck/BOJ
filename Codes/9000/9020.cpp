#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, ans1, ans2;
    scanf("%d", &t);
    bool prime[10010];
    memset(prime, true, sizeof(prime));
    for(int p = 2; p * p <= 10010; ++p) {
        if(prime[p]) {
            for(int i = p * p; i <= 10010; i += p) {
                prime[i] = 0;
            }
        }
    }
    while(t--) {
        scanf("%d", &n);
        for(int j = n / 2; j >= 2; --j) {
            if(prime[j] && prime[n - j]) {
                ans1 = j;
                ans2 = n - j;
                break;
            }
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
