#include <bits/stdc++.h>
using namespace std;

string board[21];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; ++i)
        cin >> board[i];
    vector<string> words;
    for(int i = 0; i < r; ++i) {
        string s = "";
        for(int j = 0; j < c; ++j) {
            char c = board[i][j];
            if(c == '#') {
                if(s.size() > 1)
                    words.push_back(s);
                s = "";
            } else
                s.push_back(c);
        }
        if(s.size() > 1)
            words.push_back(s);
    }
    for(int j = 0; j < c; ++j) {
        string s = "";
        for(int i = 0; i < r; ++i) {
            char c = board[i][j];
            if(c == '#') {
                if(s.size() > 1)
                    words.push_back(s);
                s = "";
            } else
                s.push_back(c);
        }
        if(s.size() > 1)
            words.push_back(s);
    }
    sort(words.begin(), words.end());
    cout << words[0];
    return 0;
}