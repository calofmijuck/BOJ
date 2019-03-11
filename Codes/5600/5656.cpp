#include <bits/stdc++.h>
using namespace std;

void t() {
    puts("true");
}

void f() {
    puts("false");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, i = 1;
    string str;
    while(cin >> a >> str >> b && str.compare("E") != 0) {
        printf("Case %d: ", i);
        int c = str[0];
        if(str.size() == 1) {
            if(c == '>' && a > b || c == '<' && a < b) t();
            else f();
        } else {
            if(c == '>' && a >= b || c == '<' && a <= b || c == '=' && a == b || c == '!' && a != b) t();
            else f();
        }
        i++;
    }
    return 0;
}
