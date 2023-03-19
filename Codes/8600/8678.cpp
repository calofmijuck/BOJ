#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (y % x == 0) {
            printf("TAK\n");
        } else {
            printf("NIE\n");
        }
    }
    return 0;
}
