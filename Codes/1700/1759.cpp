#include <bits/stdc++.h>
using namespace std;

int l, c;
char ch[16], ans[16];

void check() {
    int vow = 0, cons = 0;
    for(int i = 0; i < l; ++i) {
        char x = ans[i];
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') vow++;
        else cons++;
    }
    if(vow >= 1 && cons >= 2) {
        for(int i = 0; i < l; ++i) cout << ans[i];
        cout << '\n';
    }
}

void solve(int idx, int cnt) {
    ans[cnt] = ch[idx];
    if(cnt == l - 1) check();
    else {
        for(int i = idx + 1; i < c; ++i) solve(i, cnt + 1);
    }
    ans[cnt] = 0;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> l >> c;
    for(int i = 0; i < c; ++i) cin >> str, ch[i] = str[0];
    sort(ch, ch + c);
    for(int i = 0; i <= c - l; ++i) solve(i, 0);
}