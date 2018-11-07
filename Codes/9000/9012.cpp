#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, stat = 0;
    string str;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        stat = 0;
        cin >> str;
        bool flag = true;
        for(int j = 0; j < str.size(); ++j) {
            if(str.at(j) == '(') stat++;
            else stat--;
            if(stat < 0) {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        if(stat == 0) cout << "YES\n";
        else cout <<"NO\n";
    }
    return 0;
}
