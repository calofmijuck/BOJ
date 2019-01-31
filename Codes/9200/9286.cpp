#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m, in;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        scanf("%d", &m);
        printf("Case %d:\n", i + 1);
        for(int j = 0; j < m; ++j) {
            scanf("%d", &in);
            if(in >= 6) continue;
            else printf("%d\n", in + 1);
        }
    }
    return 0;
}
