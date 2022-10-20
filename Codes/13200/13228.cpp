#include <bits/stdc++.h>
using namespace std;

int distance_l1(int* c1, int* c2) {
    return abs(c1[0] - c2[0]) + abs(c1[1] - c2[1]) + c1[2] + c2[2];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int coordinate[2][3];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> coordinate[i][j];
            }
        }

        cout << distance_l1(coordinate[0], coordinate[1]) << '\n';
    }
    return 0;
}
