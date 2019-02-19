#include <bits/stdc++.h>
using namespace std;

int arr[101010];

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    sort(arr, arr + n, greater<int>());
    for(int i = 0; i <= n; i += 3) ans += arr[i] + arr[i + 1];
    printf("%d", ans);
    return 0;
}
