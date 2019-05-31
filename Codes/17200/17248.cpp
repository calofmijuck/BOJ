#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t, x, y, z;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &x, &y, &z);
        ll w = 2 * (y - x);
        int j = 1;
        while(j * (j + 1) * z < w) j++;
        printf("%d\n", j);
    }
    return 0;
}
