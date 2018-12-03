#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a[2];
    scanf("%lld %lld", a, a + 1);
    sort(a, a + 2);
    if(a[0] == a[1]) {
        printf("%lld", 0);
        return 0;
    }
    printf("%lld\n", a[1] - a[0] - 1);
    for(long long i = a[0] + 1; i < a[1]; ++i)
        printf("%lld ", i);
    return 0;
}
