#include <bits/stdc++.h>
using namespace std;

int main() {
    int x[4], y[4];
    for(int i = 0; i < 4; ++i) {
        scanf("%d %d", x + i, y + i);
    }
    sort(x, x + 4);
    sort(y, y + 4);
    int ans = max(x[3] - x[0], y[3] - y[0]);
    printf("%d", ans * ans);
    return 0;
}
