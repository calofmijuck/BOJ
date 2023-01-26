#include <bits/stdc++.h>
using namespace std;

int main() {
    int total, v1, v2;
    scanf("%d %d %d", &total, &v1, &v2);

    for (int i = total / v1; i >= 0; --i) {
        int remaining = total - v1 * i;
        if (remaining % v2 == 0) {
            printf("%d %d", i, remaining / v2);
            return 0;
        }
    }

    puts("Impossible");
    return 0;
}
