#include <bits/stdc++.h>
using namespace std;

int top = -1;
char st[1000100];

inline void push(char c) {
    st[++top] = c;
}

inline void pop(int k) {
    top -= k;
}

inline char get(int i) {
    return st[top - i];
}

inline int size() {
    return top + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); ++i) {
        char c = s[i];
        push(c);
        if(size() >= t.size() && c == t[t.size() - 1]) {
            bool found = true;
            for(int i = 1; i < t.size(); ++i) {
                if(t[t.size() - 1 - i] != get(i)) {
                    found = false;
                    break;
                }
            }
            if(found) pop(t.size());
        }
    }
    if(size() == 0)
        cout << "FRULA";
    else {
        for(int i = 0; i < size(); ++i)
            cout << st[i];
    }
    return 0;
}