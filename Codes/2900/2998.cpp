#include <bits/stdc++.h>
using namespace std;

char convert(char x, char y, char z) {
    return (char) '0' + 4 * (x - '0') + 2 * (y - '0') + (z - '0');
}

int main() {
    string str;
    cin >> str;
    int len = str.size(), i = 0;
    if(len % 3 == 1) {
        printf("%c", convert('0', '0', str[0]));
        i = 1;
    }
    else if(len % 3 == 2) {
        printf("%c", convert('0', str[0], str[1]));
        i = 2;
    }
    for(; i < len - 2; i += 3) printf("%c", convert(str[i], str[i + 1], str[i + 2]));
    return 0;
}
