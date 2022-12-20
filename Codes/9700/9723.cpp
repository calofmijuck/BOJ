#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int tc = 1; tc <= n; ++tc) {
        int side[3];
        scanf("%d %d %d", side, side + 1, side + 2);

        sort(side, side + 3);
        bool right = side[2] * side[2] == side[0] * side[0] + side[1] * side[1];
        printf("Case #%d: %s\n", tc, right ? "YES" : "NO");
    }
    return 0;
}
