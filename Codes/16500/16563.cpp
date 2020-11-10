#include <bits/stdc++.h>
using namespace std;

#define MAX_N 5000000

int min_factor[MAX_N + 1];

void sieve() {
    for(int p = 2; p * p <= MAX_N; ++p) {
        if(min_factor[p] > 0)
            continue;
        for(int i = p * p; i <= MAX_N; i += p) {
            if(min_factor[i] > 0) continue;
            min_factor[i] = p;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while(min_factor[x] > 0) {
            cout << min_factor[x] << ' ';
            x /= min_factor[x];    
        }
        cout << x << '\n';
    }
    return 0;
}