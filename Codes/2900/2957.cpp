#include <bits/stdc++.h>
using namespace std;

long long call = 0;

int main() {
    int n, in;
    scanf("%d %d", &n, &in);
    map<int, int> m;
    m[in] = 0;
    printf("0\n");
    for(int i = 1; i < n; ++i) {
        scanf("%d", &in);
        auto it = m.lower_bound(in);
        int cmp1 = 0, cmp2 = 0;
        if(it != m.end()) cmp1 = it -> second;
        if(it != m.begin()) cmp2 = (--it) -> second;
        m[in] = max(cmp1, cmp2) + 1;
        call += max(cmp1, cmp2) + 1;
        printf("%lld\n", call);
    }
    return 0;
}
