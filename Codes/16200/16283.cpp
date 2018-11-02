#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n, w;
    scanf("%d %d %d %d", &a, &b, &n, &w);
    if(a == b) {
        if(n * a == w) {
            if(n == 2) printf("1 1");
            else printf("-1");
            return 0;
        }
        else printf("-1");
        return 0;
    }
    int x = b * n - w, y = -a * n + w, diff = b - a;
    if(x % diff != 0 || y % diff != 0) {
        printf("-1");
        return 0;
    } else if(x / diff <= 0 || y / diff <= 0) {
            printf("-1");
            return 0;
    }
    printf("%d %d", x / diff, y / diff);
    return 0;
}
