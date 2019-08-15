#include <bits/stdc++.h>
using namespace std;

map<char, char> mp;

vector<string> pic;

int main() {
    int n, m;
    cin >> n >> m;
    mp['.'] = '.';
    mp['O'] = 'O';
    mp['-'] = '|';
    mp['|'] = '-';
    mp['/'] = '\\';
    mp['\\'] = '/';
    mp['^'] = '<';
    mp['<'] = 'v';
    mp['v'] = '>';
    mp['>'] = '^';
    pic.resize(n);
    for(int i = 0; i < n; ++i) cin >> pic[i];
    for(int i = m - 1; i >= 0; --i) {
        for(int j = 0; j < n; ++j) cout << mp[pic[j][i]];
        puts("");
    }
    return 0;
}
