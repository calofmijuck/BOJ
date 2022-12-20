#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            break;
        }

        printf("%d => %d\n", x, x * x - x + 1);
    }
    return 0;
}
