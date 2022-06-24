#include <bits/stdc++.h>
using namespace std;

int hit_count(int hp, int hit) {
    return int(ceil(double(hp) / hit));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pair<int, int> info[2];
    for (int i = 0; i < 2; ++i) {
        cin >> info[i].first >> info[i].second;
    }

    int hit_count_a = hit_count(info[0].second, info[1].first);
    int hit_count_b = hit_count(info[1].second, info[0].first);

    if (hit_count_a < hit_count_b) {
        cout << "PLAYER B";
    } else if (hit_count_a > hit_count_b) {
        cout << "PLAYER A";
    } else {
        cout << "DRAW";
    }
    return 0;
}
