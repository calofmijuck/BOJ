#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, mx, in;
    cin >> t;
    string str, ans;
    while(t--) {
        cin >> n;
        mx = 0;
        for(int i = 0; i < n; ++i) {
            cin >> in >> str;
            if(in > mx) {
                mx = in;
                ans = str;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
