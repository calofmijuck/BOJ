#include <bits/stdc++.h>
using namespace std;

int arr[2020];
bool check[2020][2020];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, s, e;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int k = 1; k <= n; ++k) {
        bool prev = 1;
        for(int i = k, j = k; 1 <= j && j <= n && 1 <= i && i <= n; j--, i++) {
            check[i][j] = prev && (arr[i] == arr[j]);
            prev = check[i][j];
        }
        prev = 1;
        for(int i = k, j = k + 1; 1 <= j && j <= n && 1 <= i && i <= n; j--, i++) {
            check[i][j] = prev && (arr[i] == arr[j]);
            prev = check[i][j];
        }
    }
    cin >> m;
    for(int k = 0; k < m; ++k) {
        cin >> s >> e;
        cout << check[e][s] << '\n';
    }
    return 0;
}