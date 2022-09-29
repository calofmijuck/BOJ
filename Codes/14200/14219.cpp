#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n % 3 == 0 or m % 3 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
