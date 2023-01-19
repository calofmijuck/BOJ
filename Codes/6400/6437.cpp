#include <bits/stdc++.h>
using namespace std;

vector<string> result = { "Hole-in-one.", "Double eagle.", "Eagle.", "Birdie.", "Par.", "Bogey.", "Double Bogey." };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int par, stroke, hole = 1;
    while (true) {
        cin >> par >> stroke;
        if (par == 0 && stroke == 0) {
            break;
        }

        cout << "Hole #" << hole << '\n';
        if (stroke == 1) {
            cout << result[0];
        } else {
            int diff = min(stroke - par, 2);
            cout << result[diff + 4];
        }

        cout << "\n\n";
        hole++;
    }

    return 0;
}
