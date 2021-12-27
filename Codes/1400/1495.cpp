#include <bits/stdc++.h>
using namespace std;

int songs, start_volume, max_volume;
vector<int> change;
bool possible[51][1001];

bool in_range(int volume) {
    return 0 <= volume && volume <= max_volume;
}

int find_max_volume() {
    possible[0][start_volume] = true;
    for (int i = 1; i <= songs; ++i) {
        for (int volume = 0; volume <= max_volume; ++volume) {
            if (possible[i - 1][volume]) {
                int next_up = volume + change[i];
                if (in_range(next_up)) {
                    possible[i][next_up] = true;
                }

                int next_down = volume - change[i];
                if (in_range(next_down)) {
                    possible[i][next_down] = true;
                }
            }
        }
    }

    for (int volume = max_volume; volume >= 0; --volume) {
        if (possible[songs][volume]) {
            return volume;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> songs >> start_volume >> max_volume;
    change.resize(songs + 1);
    for (int i = 1; i <= songs; ++i) {
        cin >> change[i];
    }

    cout << find_max_volume();
    return 0;
}
