#include <bits/stdc++.h>
using namespace std;

int main() {
    bool cup[4] = {0, 1, 0, 0};
    int n, x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        bool tmp = cup[y];
        cup[y] = cup[x];
        cup[x] = tmp;
    }
    for(int i = 1; i < 4; i++) {
        if(cup[i]) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
