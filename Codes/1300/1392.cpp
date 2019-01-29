#include <bits/stdc++.h>
using namespace std;

int arr[10101];

int main() {
    int n, q, in, p = 0;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &in);
        for(int k = in; k > 0; --k) arr[p++] = i;
    }
    for(int i = 0; i < q; ++i) {
        scanf("%d", &in);
        printf("%d\n", arr[in]);
    }
    return 0;
}
