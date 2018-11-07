#include <bits/stdc++.h>
using namespace std;

bool prime[300000];

int main() {
    int n;
    memset(prime, true, sizeof(prime));
    for(int p = 2; p * p <= 300000; ++p) {
        if(prime[p]) {
            for(int i = p * p; i <= 300000; i += p) {
                prime[i] = 0;
            }
        }
    }
    int cnt;
    while(scanf("%d", &n) && n) {
        cnt = 0;
        for(int i = n + 1; i <= 2 * n; ++i) {
            if(prime[i]) ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
