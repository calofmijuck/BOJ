#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<string, bool> mp;
    string name, stat;
    for(int i = 0; i < n; ++i) {
        cin >> name >> stat;
        if(stat[0] == 'e') mp[name] = true;
        else mp.erase(name);
    }
    vector<string> vec;
    for(auto it = mp.begin(); it != mp.end(); ++it)
        vec.push_back(it -> first);
    sort(vec.begin(), vec.end());
    for(int i = vec.size() - 1; i >= 0; --i) {
        cout << vec[i] << '\n';
    }
    return 0;
}
