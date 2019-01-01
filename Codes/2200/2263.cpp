#include <bits/stdc++.h>
using namespace std;

int n, in, post[101010], pos[101010];

void preorder(int st, int ed, int from) {
    if(ed < st) return;
    if(ed == st) {
        printf("%d ", post[st]);
        return;
    }
    printf("%d ", post[ed]);
    int idx = pos[post[ed]];
    preorder(st, st + idx - from - 1, from);
    preorder(st + idx - from, ed - 1, idx + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &in);
        pos[in] = i;
    }
    for(int i = 0; i < n; ++i) scanf("%d", post + i);
    preorder(0, n - 1, 0);
    return 0;
}
