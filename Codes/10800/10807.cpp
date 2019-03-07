#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    int n, v, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    scanf("%d", &v);
    for(int i = 0; i < n; ++i) {
        if(arr[i] == v) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
