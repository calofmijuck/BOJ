#include <bits/stdc++.h>
using namespace std;
#define MAX 2147483647

int main() {
    int n, x, y, max1 = -MAX, min1 = MAX, max2 = -MAX, min2 = MAX;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        max1 = max(max1, x + y);
        min1 = min(min1, x + y);
        max2 = max(max2, y - x);
        min2 = min(min2, y - x);
    }
    printf("%d", max(max1 - min1, max2 - min2));
    return 0;
}
