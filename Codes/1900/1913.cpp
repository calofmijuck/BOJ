#include <iostream>
using namespace std;

int main() {
    int n, k, curr = 1;
    cin >> n >> k;
    int arr[n][n], x = n / 2, y = n / 2;
    arr[x][y] = curr++;
    for(int i = 1; i <= n / 2; ++i) {
        int offset = 2 * i;
        x--; y--;
        for(int j = 0; j < offset; ++j)
            arr[x][++y] = curr++;
        for(int j = 0; j < offset; ++j)
            arr[++x][y] = curr++;
        for(int j = 0; j < offset; ++j)
            arr[x][--y] = curr++;
        for(int j = 0; j < offset; ++j)
            arr[--x][y] = curr++;
    }
    int ans1, ans2;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%d ", arr[i][j]);
            if(arr[i][j] == k) {
                ans1 = i + 1;
                ans2 = j + 1;
            }
        }
        puts("");
    }
    printf("%d %d", ans1, ans2);
}
