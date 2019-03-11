#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while(getline(cin, str) && str[0] != '#') {
        int sum = 0;
        for(int i = 1; i <= (int) str.size(); ++i) {
            char c = str[i - 1];
            if('A' <= c && c <= 'Z') sum += i * (c - 'A' + 1);
        }
        printf("%d\n", sum);
    }
    return 0;
}
