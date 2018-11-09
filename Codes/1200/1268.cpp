#include <bits/stdc++.h>
using namespace std;

int res[1010];
bool same[1010];

int main() {
    int n, max = 0, ret = 0;
    scanf("%d", &n);
    int arr[n][5];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 5; ++j)
            scanf("%d", &arr[i][j]);
    }
    for(int i = 0; i < n; ++i) {
        memset(same, false, sizeof(same));
        for(int j = 0; j < 5; ++j) {
            int curr = arr[i][j];
            for(int k = 0; k < n; ++k) {
                if(arr[k][j] == curr)
                    same[k] = true;
            }
        }
        int cnt = -1;
        for(int j = 0; j < n; ++j) {
            if(same[j]) ++cnt;
        }
        res[i] = cnt;
    }
    for(int i = 0; i < n; ++i) {
        if(res[i] > max) {
            max = res[i];
            ret = i;
        }
    }
    printf("%d", ret + 1);
    return 0;
}
