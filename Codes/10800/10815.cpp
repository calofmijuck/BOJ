#include <bits/stdc++.h>
using namespace std;

int arr[505050], in;

bool search(int st, int ed) {
    while(st <= ed) {
        int mid = (st + ed) >> 1;
        int x = arr[mid];
        if(in == x) return true;
        else if(in > x) {
            st = mid + 1;
        } else ed = mid - 1;
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    scanf("%d", &m);
    sort(arr, arr + n);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &in);
        if(search(0, n - 1)) printf("1 ");
        else printf("0 ");
    }
    return 0;

}
