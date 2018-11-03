#include <cstdio>
using namespace std;

int main(){
    int s, k;
    scanf("%d %d", &s, &k);
    int m = s / k, r = s % k;
    long long res = 1;
    for(int i = 0; i < k; i++) {
        res *= (i < k - r ? m : m + 1);
    }
    printf("%lld\n", res);
}
