#include <iostream>
using namespace std;
typedef long long ll;

ll arr[1050][1050];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
        for(int j = 1; j <= n; ++j) arr[i][j] += arr[i - 1][j];
    }
    for(int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1] << '\n';
    }
}
