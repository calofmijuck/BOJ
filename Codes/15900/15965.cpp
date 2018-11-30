#include <bits/stdc++.h>
using namespace std;

bitset<10101010> prime;

int main() {
    int n = 10101010, k, cnt = 0;
    scanf("%d", &k);
    prime.set();
    for(int p = 2; p * p <= n; p++) {
        if(prime[p] == true) {
            for(int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    for(int i = 2; i < n; i++) {
        if(prime[i]) cnt++;
        if(cnt == k) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
