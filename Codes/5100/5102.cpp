#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int total, out_of_bed;
    while (true) {
        cin >> total >> out_of_bed;
        if (total == 0 && out_of_bed == 0) {
            break;
        }

        int diff = total - out_of_bed;
        if (diff == 1) {
            cout << "0 0\n";
        } else {
            bool group_of_three = (diff % 2 == 1);
            cout << (diff / 2) - group_of_three << ' ' << group_of_three << '\n';
        }
    }
    return 0;
}
