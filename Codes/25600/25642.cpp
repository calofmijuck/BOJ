#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int yongtae, yujin;
    cin >> yongtae >> yujin;

    bool turn = false;
    while (true) {
        if (turn) {
            yongtae += yujin;
        } else {
            yujin += yongtae;
        }

        if (yongtae >= 5) {
            cout << "yj";
            break;
        } else if (yujin >= 5) {
            cout << "yt";
            break;
        }

        turn = !turn;
    }
    return 0;
}
