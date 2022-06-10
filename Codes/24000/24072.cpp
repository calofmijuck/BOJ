#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << (int) (a <= c and c < b);
    return 0;
}
