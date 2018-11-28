#include <bits/stdc++.h>
using namespace std;

bool before8(string str) {
    if(!str.compare("January") || !str.compare("March") || !str.compare("April") || !str.compare("May") || !str.compare("June") || !str.compare("July")) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string str;
    while(cin >> n >> str) {
        if(n == 0) break;
        if(str.compare("August") == 0) {
            if(n < 4) cout << "Yes\n";
            else if(n > 4) cout << "No\n";
            else cout << "Happy birthday\n";
        } else if(str.compare("February") == 0) {
            if(n == 29) cout << "Unlucky\n";
            else cout << "Yes\n";
        } else if(before8(str)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
