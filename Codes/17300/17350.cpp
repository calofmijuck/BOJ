#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        if(str == "anj") {
            cout << "뭐야;";
            return 0;
        }
    }
    cout << "뭐야?";
    return 0;
}
