#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string l, r;
    cin >> l >> r;
    if(l.size() != r.size()) {
        cout << 0;
    } else {
        int ans = 0;
        for(int i = 0; i < l.size(); ++i) {
            if(l[i] != r[i])
                break;
            else if(l[i] == '8' && r[i] == '8')
                ++ans;
        }
        cout << ans;
    }
    return 0;
}