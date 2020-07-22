#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    vector<int> colons;
    for(int i = 0; i < str.size(); ++i)
        if(str[i] == ':')
            colons.push_back(i);
    if(colons.size() == 7) {
        int prev = 0, next;
        for(int i = 0; i < colons.size(); ++i) {
            next = colons[i];
            string s = str.substr(prev, next - prev);
            for(int j = 0; j < 4 - (int) s.size(); ++j) cout << '0';
            cout << s << ':';
            prev = next + 1;
        }
        string s = str.substr(prev, str.size() - prev);
        for(int j = 0; j < 4 - (int) s.size(); ++j) cout << '0';
        cout << s;        
    } else {
        int group = 7 - colons.size() + 1;
        int prev = 0, next;
        for(int i = 0; i < colons.size(); ++i) {
            next = colons[i];
            if(i - 1 >= 0 && colons[i - 1] == next - 1) {
                for(int j = 0; j < group; ++j) {
                    cout << "0000:";
                }
            } else {
                string s = str.substr(prev, next - prev);
                for(int j = 0; j < 4 - (int) s.size(); ++j) cout << '0';
                cout << s << ':';
            }
            prev = next + 1;
        }
        string s = str.substr(prev, str.size() - prev);
        for(int j = 0; j < 4 - (int) s.size(); ++j) cout << '0';
        cout << s; 
    }
    return 0;
}