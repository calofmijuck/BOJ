#include <bits/stdc++.h>
using namespace std;

int arr[101010];

int main() {
    int n, x, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    scanf("%d", &x);
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i) {
        if(arr[i] == x / 2 && x % 2 == 0) continue;
        if(binary_search(arr, arr + n, x - arr[i])) ans++;
    }
    printf("%d", ans / 2);
    return 0;
}
