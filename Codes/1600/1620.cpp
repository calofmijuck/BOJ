#include <bits/stdc++.h>
using namespace std;

int atoi(string str) {
    int ret = 0;
    for(int i = 0; i < str.size(); ++i) {
        ret *= 10;
        ret += str[i] - '0';
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string str;
    vector<string> vec;
    map<string, int> mp;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        mp[str] = i + 1;
        vec.push_back(str);
    }
    for(int i = 0; i < m; ++i) {
        cin >> str;
        if('0' <= str[0] && str[0] <= '9') {
            int num = atoi(str);
            cout << vec[num - 1] << '\n';
        } else {
            cout << mp[str] << '\n';
        }
    }
    return 0;
}
