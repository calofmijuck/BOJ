#include <bits/stdc++.h>
using namespace std;

bool vowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else return false;
}

int main() {
    string str;
    while(cin >> str) {
        if(!str.compare("end")) break;
        int con = 0, vow = 0;
        bool evow = false, accept = true;
        for(int i = 0; i < (int) str.size(); ++i) {
            if(!evow && vowel(str[i])) evow = true;
            if(vowel(str[i])) {
                vow++;
                con = 0;
            } else {
                con++;
                vow = 0;
            }
            if(vow > 2 || con > 2) {
                accept = false;
                break;
            }
            if(i != 0 && str[i] == str[i - 1]) {
                if(str[i] != 'e' && str[i] != 'o') {
                    accept = false;
                    break;
                }
            }
        }
        cout << '<' << str << "> is ";
        if(!evow || !accept) {
            printf("not ");
        }
        printf("acceptable.\n");
    }
    return 0;
}
