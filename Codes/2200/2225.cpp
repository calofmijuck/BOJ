#include <iostream>
using namespace std;
typedef long long ll;

#define MOD 1000000000

ll C[410][410];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    C[0][0] = 1;
    for(int i = 1; i <= 400; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    cout << C[n + k - 1][n];
}