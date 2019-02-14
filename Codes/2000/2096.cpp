#include <bits/stdc++.h>
using namespace std;

int arr[3], mi[3], mx[3], x, y, z;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) scanf("%d", arr + j);
        x = mi[0], y = mi[1], z = mi[2];
        mi[0] = min(x, y) + arr[0];
        mi[1] = min({x, y, z}) + arr[1];
        mi[2] = min(y, z) + arr[2];
        x = mx[0], y = mx[1], z = mx[2];
        mx[0] = max(x, y) + arr[0];
        mx[1] = max({x, y, z}) + arr[1];
        mx[2] = max(y, z) + arr[2];
    }
    printf("%d %d", max({mx[0], mx[1], mx[2]}), min({mi[0], mi[1], mi[2]}));
    return 0;
}
