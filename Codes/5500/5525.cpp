#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, cnt = 0, ans = 0;
    string str;
    cin >> n >> m >> str;
    vector<int> vec;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == 'I') {
            while(i < str.size() - 2) {
                if(str[i + 1] == 'O' && str[i + 2] == 'I') {
                    cnt++;
                    i += 2;
                } else {
                    vec.push_back(cnt);
                    cnt = 0;
                    break;
                }
            }
        }
    }
    vec.push_back(cnt);
    for(int i = 0; i < vec.size(); ++i)
        ans += (vec[i] - n + 1 > 0) ? (vec[i] - n + 1) : 0;
    cout << ans;
}
