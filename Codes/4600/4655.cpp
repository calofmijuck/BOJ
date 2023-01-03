#include <bits/stdc++.h>
using namespace std;

int calculate_cards(double overhang) {
    double hang = 0;
    int card = 0;
    while (hang < overhang) {
        card++;
        hang += 1.0 / (card + 1);
    }
    return card;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double overhang = 0;
    while (true) {
        cin >> overhang;
        if (overhang == 0) {
            break;
        }

        cout << calculate_cards(overhang) << " card(s)\n";
    }
    return 0;
}
