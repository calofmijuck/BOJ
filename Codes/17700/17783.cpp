#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "Alice" << '\n' << '1';
    } else {
        cout << "Bob";
    }
    return 0;
}
