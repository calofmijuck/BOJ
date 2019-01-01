#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, k, p;
    scanf("%d %d %d", &c, &k, &p);
    printf("%d", c * (c + 1) / 2 * k + c * (c + 1) * (2 * c + 1) / 6 * p);
    return 0;
}
