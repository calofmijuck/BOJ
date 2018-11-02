#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for(int p = 2; p * p <= n; p++) {
        if(prime[p] == true) {
            for(int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i < n; i++) {
        if(prime[i]) {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
