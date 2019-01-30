#include <bits/stdc++.h>
using namespace std;

int arr[1010];
bool visited[1010];

void dfs(int i) {
    visited[i] = true;
    if(!visited[arr[i]]) dfs(arr[i]);
    else return;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        int ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", arr + i);
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <= n; ++i) {
            if(!visited[i]) {
                ans++;
                dfs(i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
