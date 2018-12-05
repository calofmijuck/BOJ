#include <bits/stdc++.h>
using namespace std;

int avail[32];

int main() {
    int n, st, ed, k, max = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &st, &ed);
        for(int j = st; j < ed; ++j)
            avail[j]++;
    }
    scanf("%d", &k);
    for(int i = 1; i <= 31; ++i) {
        if(avail[i] > max) max = avail[i];
    }
    if(k >= max) printf("1");
    else printf("0");

    return 0;
}
