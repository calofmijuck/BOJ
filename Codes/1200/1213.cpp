#include <iostream>
using namespace std;

int cnt[30];

int main() {
    string str;
    cin >> str;
    int odd = 0;
    char oddchar;
    for(int i = 0; i < str.size(); ++i) cnt[str[i] - 'A']++;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] % 2 != 0) {
            odd++;
            oddchar = 'A' + i;
            if(odd > 1) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < cnt[i] / 2; ++j) {
            cout << (char) ('A' + i);
        }
    }
    if(odd == 1) cout << oddchar;
    for(int i = 25; i >= 0; --i) {
        for(int j = 0; j < cnt[i] / 2; ++j) {
            cout << (char) ('A' + i);
        }
    }
}