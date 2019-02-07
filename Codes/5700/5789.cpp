#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string str;
    scanf("%d", &t);
    while(t--) {
        cin >> str;
        int len = (int) str.size();
        if(str[len / 2] == str[len / 2 - 1]) puts("Do-it");
        else puts("Do-it-Not");
    }
    return 0;
}
