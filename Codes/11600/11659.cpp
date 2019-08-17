#include <iostream>
using namespace std;

int arr[101010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        cout << arr[y] - arr[x - 1] << '\n';
    }
    return 0;
}
