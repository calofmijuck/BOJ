#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;
    string str;
    cin >> a >> b >> str;
    char c = str[str.size() - 1];
    if((c - '0') % 2) {
        cout << (a ^ b);
    } else {
        cout << a;
    }
    return 0;
}
