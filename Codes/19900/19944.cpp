#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if(m == 1 || m == 2) {
        cout << "NEWBIE!";
    } else if(m <= n) {
        cout << "OLDBIE!";
    } else {
        cout << "TLE!";
    }
    return 0;
}