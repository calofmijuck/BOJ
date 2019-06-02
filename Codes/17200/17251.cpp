#include <bits/stdc++.h>
using namespace std;

int arr[1010101], rmax[1010101], bmax[1010101];

int main() {
    int n, r = 0, b = 0;
    scanf("%d %d", &n, &arr[0]);
    rmax[0] = arr[0];
    for(int i = 1; i < n; ++i) {
        scanf("%d", arr + i);
        rmax[i] = max(arr[i], rmax[i - 1]);
    }
    bmax[n - 2] = arr[n - 1];
    for(int i = n - 3; i >= 0; --i) bmax[i] = max(bmax[i + 1], arr[i + 1]);
    for(int i = 0; i < n - 1; ++i) {
        if(rmax[i] > bmax[i]) r++;
        else if(rmax[i] < bmax[i]) b++;
    }
    if(r > b) puts("R");
    else if(r < b) puts("B");
    else puts("X");
    return 0;
}
