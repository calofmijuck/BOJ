#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll r, c, n, ans;
    cin >> r >> c >> n;
    ans = ((r + n - 1) / n) * ((c + n - 1) / n);
    cout << ans;
}
