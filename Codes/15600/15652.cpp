#include <iostream>
using namespace std;

bool visited[10];
int arr[10];
int m, n;

void solve(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; ++i) cout << arr[i] + 1 << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; ++i) {
        arr[cnt] = i;
        if(cnt != 0 && arr[cnt - 1] <= arr[cnt]) solve(cnt + 1);
        if(cnt == 0) solve(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    solve(0);
    return 0;
}
