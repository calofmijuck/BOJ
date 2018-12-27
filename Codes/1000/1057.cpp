#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, ans = 1;
    scanf("%d %d %d", &n, &x, &y);
    while(x != y) {
        x -= x / 2;
        y -= y / 2;
        if(x != y) ans++;
    }
    printf("%d", ans);
    return 0;
}
