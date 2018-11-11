#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, ans = 0;
    scanf("%d", &x);
    do {
        if(x & 1) ans++;
    } while(x >>= 1);
    printf("%d", ans);
}
