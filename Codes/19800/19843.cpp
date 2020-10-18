#include <bits/stdc++.h>
using namespace std;

map<string, int> mp = {
    {"Mon", 0}, {"Tue", 24}, {"Wed", 48}, {"Thu", 72}, {"Fri", 96} 
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, total = 0;
    cin >> t >> n;
    for(int i = 0; i < n; ++i) {
        string st, ed;
        int x, y;
        cin >> st >> x >> ed >> y;
        int st_time = mp[st] + x;
        int ed_time = mp[ed] + y;
        total += ed_time - st_time;
    }
    if(total >= t) {
        cout << 0;
    } else if(total + 48 < t) {
        cout << -1;
    } else {
        cout << t - total;
    }
    return 0;
}