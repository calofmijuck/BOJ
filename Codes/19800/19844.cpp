#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void process(string s);

vector<string> split(string str, char c) {
    vector<string> ret;
    int prev = 0, next = str.find(c, prev);
    while((next = str.find(c, prev)) != string::npos) {
        string s = str.substr(prev, next - prev);
        ret.push_back(s);
        prev = next + 1;
    }
    string s = str.substr(prev);
    ret.push_back(s);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    getline(cin, str);
    vector<string> list;
    vector<string> arr = split(str, ' ');
    for(string s : arr) {
        int idx = s.find('-');
        if(idx >= 0) {
            vector<string> tmp = split(s, '-');
            for(string t : tmp)
                list.push_back(t);
        } else
            list.push_back(s);
    }
    for(string s : list)
        process(s);
    cout << ans;
    return 0;
}

void process(string s) {
    if(s.size() < 3) {
        ans++;
        return;
    }
    char c = s[0], d = s[1], e = s[2];
    if(d == '\'') {
        if(strchr("cjnmtsld", c) && strchr("aeiouh", e)) {
            ans += 2;
            return;
        }
    } else if(e == '\'') {
        if(c == 'q' && d == 'u' && s.size() >= 4) {
            char f = s[3];
            if(strchr("aeiouh", f)) {
                ans += 2;
                return;
            }
        }
    }
    ans++;
}