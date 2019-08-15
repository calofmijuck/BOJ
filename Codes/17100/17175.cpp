#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int x = 1, y = 1, z;
    if(n < 2) cout << 1;
    else {
        for(int i = 2; i <= n; ++i) {
            z = x + y + 1;
            z %= 1000000007;
            x = y, y = z;
        }
        cout << z;
    }
}
