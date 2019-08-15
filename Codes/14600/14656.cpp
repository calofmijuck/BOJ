#include <iostream>
using namespace std;

int main() {
    int n, ans = 0, x;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        if(i != x) ans++;
    }
    cout << ans;
}
