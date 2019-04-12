#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    string str, ans;
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        mp[str]++;
    }
    for(auto s : mp) {
        if(mp[s.first] > cnt) {
            ans = s.first;
            cnt = mp[s.first];
        }
    }
    cout << ans;
    return 0;
}
