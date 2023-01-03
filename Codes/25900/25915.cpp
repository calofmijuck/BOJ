#include <bits/stdc++.h>
using namespace std;

string password = "ILOVEYONSEI";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    char c;
    cin >> c;

    int dist = 0;
    for (char x : password) {
        dist += abs(x - c);
        c = x;
    }
    cout << dist;
    return 0;
}
