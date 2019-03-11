#include <bits/stdc++.h>
using namespace std;

int arr[1010][1010];

int main() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    x--, y--;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) scanf("%d", &arr[i][j]);
    }
    for(int i = 0; i < n; ++i) {
        if(arr[x][i] > arr[x][y]) {
            printf("ANGRY");
            return 0;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(arr[i][y] > arr[x][y]) {
            printf("ANGRY");
            return 0;
        }
    }
    printf("HAPPY");
    return 0;
}
