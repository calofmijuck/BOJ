#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[101010];
ll psum[101010];

int main() {
    int n, m, st, ed;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        psum[i] = psum[i - 1] + arr[i];
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &st, &ed);
        printf("%lld\n", psum[ed + 1] - psum[st]);
    }
    return 0;
}
