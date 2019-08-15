#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(c % 2 == 0) {
        cout << (a ^ 0);
    } else {
        cout << (a ^ b);
    }
    return 0;
}
