#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str, title = "";
    getline(cin, str);
    int space, cnt[26];
    cin >> space;
    for(int i = 0; i < 26; ++i)
        cin >> cnt[i];
    for(int i = 0; i < str.size(); ++i) {
        char prev = (i > 0) ? str[i - 1] : ' ';
        char curr = str[i];
        if(prev != curr) {
            if(curr == ' ') {
                space--;
                if(space < 0) {
                    cout << - 1;
                    return 0;
                }
            } else {
                int idx = ('a' <= curr && curr <= 'z') ? curr - 'a' : curr - 'A';
                cnt[idx]--;
                if(prev == ' ') {
                    title.push_back('A' + idx);
                    cnt[idx]--;
                }
                if(cnt[idx] < 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << title;
    return 0;
}