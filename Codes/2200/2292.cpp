#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k = 0;
    scanf("%d", &n);
    if(n == 1) {
        printf("1");
        return 0;
    }
    while(3 * k * k - 3 * k + 1 < n) {
        ++k;
    }
    printf("%d", k);
    return 0;
}
