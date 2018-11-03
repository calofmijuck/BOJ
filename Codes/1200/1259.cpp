#include <bits/stdc++.h>
using namespace std;

bool isPalin(string str) {
    if(str.size() <= 1) return true;
    for(int i = 0; i < str.size() / 2; i++) {
        if(str.at(i) != str.at(str.size() - i - 1)) return false;
    }
    return true;
}

int main(){
    string str;
    while(cin >> str && str.compare("0") != 0) {
        if(isPalin(str)) printf("yes\n");
        else printf("no\n");
    }
}
