#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int treats[3];
    for (int i = 0; i < 3; ++i) {
        cin >> treats[i];
    }

    int score = treats[0] + 2 * treats[1] + 3 * treats[2];
    if (score >= 10) {
        cout << "happy";
    } else {
        cout << "sad";
    }
    return 0;
}
