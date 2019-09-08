#include <iostream>
using namespace std;

int gph[210][210];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        gph[x][y] = gph[y][x] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            for(int k = j + 1; k <= n; ++k) {
                if(gph[i][j] == 0 && gph[j][k] == 0 && gph[k][i] == 0) cnt++;
            }
        }
    }
    cout << cnt;
}