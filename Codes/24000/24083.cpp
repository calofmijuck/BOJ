#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;

    cin >> a >> b;

    int time = (a + b) % 12;
    cout << ((time == 0) ? 12 : time);
    return 0;
}
