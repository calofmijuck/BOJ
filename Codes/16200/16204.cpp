#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int res = min(m, k) + min(n - m, n - k);
    printf("%d", res);
    return 0;
}
