#include <bits/stdc++.h>
using namespace std;

int find_min_undividing(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            continue;
        }

        return i;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d %d", find_min_undividing(n), n - 1);
    return 0;
}
