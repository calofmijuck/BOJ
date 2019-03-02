#include <bits/stdc++.h>
using namespace std;

char encrypt(char c, char d) {
    int x = c - 'a', offset = d - 'a' + 1;
    x -= offset;
    if(x < 0) x += 26;
    return (char) (x + 'a');
}

int main() {
    string str, key;
    getline(cin, str);
    getline(cin, key);
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == ' ') {
            printf(" ");
            continue;
        }
        printf("%c", encrypt(str[i], key[i % key.size()]));
    }
    return 0;
}
