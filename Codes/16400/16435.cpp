#include <bits/stdc++.h>
using namespace std;

int height[1010];

int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; ++i) scanf("%d", height + i);
    sort(height, height + n);
    for(int i = 0; i < n; ++i) {
        if(height[i] <= l) ++l;
        else break;
    }
    printf("%d", l);
    return 0;
}
