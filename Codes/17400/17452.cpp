#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define INF 0x3f3f3f3f

string str[101010];
pii idx[27][101010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> str[i];

        for(int j = 0; j < 26; ++j) idx[j][i] = {INF, INF};
        for(int j = 0; j < str[i].size(); ++j) {
            int c = str[i][j] - 'a';
            idx[c][i].first = min(idx[c][i].first, j);
            idx[c][i].second = min(idx[c][i].second, (int) str[i].size() - j - 1);
        }
    }
    
    int mi = INF;
    for(int j = 0; j < 26; ++j) {
        int f = INF, s = INF, ff = INF, ss = INF;
        int fi = 0, si = 0, ffi, ssi;
        for(int i = 0; i < n; ++i) {
            pii p = idx[j][i];
            if(f >= p.first) {
                ff = f, ffi = fi;
                f = p.first, fi = i;
            }
            if(s >= p.second) {
                ss = s, ssi = si;
                s = p.second, si = i;
            }
        }
        if(fi == si) {
            mi = min({mi, f + ss, s + ff});
            if(ffi != ssi) mi = min(mi, ff + ss);
        } else mi = min(mi, f + s);
    }
    if(mi >= INF) cout << -1;
    else cout << mi;
}