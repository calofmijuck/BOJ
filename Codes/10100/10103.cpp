#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s1 = 100, s2 = 100, x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if(x > y) s2 -= x;
        else if(x < y) s1 -= y;
    }
    printf("%d\n%d", s1, s2);
    return 0;
}
