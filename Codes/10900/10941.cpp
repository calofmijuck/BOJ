#include <bits/stdc++.h>
using namespace std;

int hex(char i, char j) {
    int ret = 0;
    if('A' <= i && i <= 'F') ret += i - 'A' + 10;
    else ret += i - '0';
    ret *= 16;
    if('A' <= j && j <= 'F') ret += j - 'A' + 10;
    else ret += j - '0';
    return ret;
}

int main() {
    string str;
    cin >> str;
    for(int i = 1; i < str.size(); i += 2) {
        printf("%c", (char) hex(str[i - 1], str[i]));
    }
    return 0;
}
