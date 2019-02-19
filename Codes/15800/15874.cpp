#include <bits/stdc++.h>
using namespace std;

char push(char c, int k) {
    if('A' <= c && c <= 'Z') c = 'A' + (c - 'A' + k) % 26;
    else if('a' <= c && c <= 'z') c = 'a' + (c - 'a' + k) % 26;
    return c;
}

int main() {
    int k, s;
    string str;
    scanf("%d %d\n", &k, &s);
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i) {
        printf("%c", push(str[i], k));
    }
    return 0;
}
