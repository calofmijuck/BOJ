#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const unsigned int N = 1000000007;

ull log(ull n) {
    ull k = 0;
    while(n % 3 == 0) n /= 3, k++;
    return k;
}

bool cmp(ull p, ull q) {
    if((log(p) != log(q)) && (log(p) != 0 || log(q) != 0)) return log(p) > log(q);
    else return p < q;
}

ull arr[110];

int main() {
    ull n;
    scanf("%llu", &n);
    for(int i = 0; i < n; ++i) scanf("%llu", arr + i);
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; ++i) printf("%llu ", arr[i]);
    return 0;
}
