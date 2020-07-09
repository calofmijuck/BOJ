#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

ll gph[8][8] = {
    0, 1, 1, 0, 0, 0, 0, 0,
    1, 0, 1, 1, 0, 0, 0, 0,
    1, 1, 0, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 1, 1, 0, 0,
    0, 0, 1, 1, 0, 1, 0, 1,
    0, 0, 0, 1, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 1,
    0, 0, 0, 0, 1, 0, 1, 0
};

void matmul(ll A[][8], ll B[][8]) {
    ll tmp[8][8] = {0};
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            ll s = 0;
            for(int k = 0; k < 8; ++k)
                s = (s + A[i][k] * B[k][j]) % MOD;
            tmp[i][j] = s;
        }
    }
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j)
            A[i][j] = tmp[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ll ans[8][8] = {0};
    for(int i = 0; i < 8; ++i) ans[i][i] = 1;
    while(n > 0) {
        if(n & 1)
            matmul(ans, gph);
        matmul(gph, gph);
        n >>= 1;
    }
    cout << ans[0][0];
    return 0;
}