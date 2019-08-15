#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int set = 0;
    int n, x;
    cin >> n;
    string str;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        char cmd = str[0];
        if(cmd == 'a') {
            if(str[1] == 'l') {
                set = 2097150;
            } else {
                cin >> x;
                set |= (1 << x);
            }
        } else if(cmd == 'r') {
            cin >> x;
            set &= ~(1 << x);
        } else if(cmd == 't') {
            cin >> x;
            set ^= (1 << x);
        } else if(cmd == 'c') {
            cin >> x;
            if(set & (1 << x)) {
                cout << 1 << '\n';
            } else cout << 0 << '\n';
        } else if(cmd == 'e') {
            set = 0;
        }
    }
    return 0;
}
