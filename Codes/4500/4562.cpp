#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int zombies, brains;
        cin >> zombies >> brains;

        if (zombies < brains) {
            cout << "NO BRAINS\n";
        } else {
            cout << "MMM BRAINS\n";
        }
    }
    return 0;
}
