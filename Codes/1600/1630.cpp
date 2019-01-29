#include <bitset>
#include <cstdio>
using namespace std;
typedef long long ll;

bitset<1000001> prime;

int main() {
    ll n, tmp, ans = 1;
    scanf("%lld", &n);
    for(ll i = 2; i <= n; ++i) {
        if(prime[i]) continue;
        tmp = n;
        while((tmp /= i) >= 1) ans = ans * i % 987654321;
        for(ll j = i * i; j <= n; j += i) prime[j] = true;
    }
    printf("%lld", ans);
    return 0;
}
