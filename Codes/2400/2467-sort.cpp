#include <bits/stdc++.h>
using namespace std;

#define MAX 0x7f7f7f7f

int arr[100010], mi = MAX, res[2];

bool cmp(int a, int b) {
    return abs(a) > abs(b);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) 
		scanf("%d", arr + i);
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n - 1; ++i) {
        if(abs(arr[i] + arr[i + 1]) < mi) {
            mi = abs(arr[i] + arr[i + 1]);
            res[0] = arr[i];
            res[1] = arr[i + 1];
        }
    }
    sort(res, res + 2);
    printf("%d %d", res[0], res[1]);
    return 0;
}
