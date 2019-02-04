#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); ++i) {
        char c = str.at(i);
        if(c - 'A' >= 0 && 'Z' - c >= 0) printf("%c", c);
    }
    return 0;
}
