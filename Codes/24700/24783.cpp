#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c) {
    return a + b == c || a - b == c || a * b == c || double(a) / b == c || b - a == c || double(b) / a == c;
}

void find_combination() {
    int a, b, c;
    cin >> a >> b >> c;

    if (check(a, b, c)) {
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cases;
    cin >> cases;

    while (cases--) {
        find_combination();
    }
    return 0;
}
