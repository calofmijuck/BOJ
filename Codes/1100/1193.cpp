#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n = 1;
    scanf("%d", &x);
    while(n * (n - 1) < 2 * x - 1) {
        ++n;
    }
    int g = n - 1, k = x - (n - 1) * (n - 2) / 2;
    if(g & 1) printf("%d/%d", n - k, k);
    else printf("%d/%d", k, n - k);
    return 0;
}
