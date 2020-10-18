#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int arr[MAX_N + 2], dx[MAX_N + 2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    for(int i = 0; i < m; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        dx[l] += k;
        dx[r + 1] -= k;
    }
    for(int i = 1; i <= n; ++i) {
        dx[i] += dx[i - 1];
        cout << dx[i] + arr[i] << ' ';
    }
    return 0;
}