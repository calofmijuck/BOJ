#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) arr[i] = i;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        swap(arr[x], arr[y]);
    }
    for(int i = 1; i <= n; ++i) printf("%d ", arr[i]);
    return 0;
}
