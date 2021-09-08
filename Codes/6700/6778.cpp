#include <bits/stdc++.h>
using namespace std;

int antenna, eyes;

bool troy_martian() {
    return antenna >= 3 && eyes <= 4;
}

bool vlad_saturnian() {
    return antenna <= 6 && eyes >= 2;
}

bool graeme_mercurian() {
    return antenna <= 2 && eyes <= 3;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> antenna >> eyes;
    if (troy_martian()) {
        cout << "TroyMartian\n";
    }
    if (vlad_saturnian()) {
        cout << "VladSaturnian\n";
    }
    if (graeme_mercurian()) {
        cout << "GraemeMercurian\n";
    }
    return 0;
}
