#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int check_attack(int arrival_time, pii& dog) {
    int period = dog.first + dog.second;
    int r = arrival_time % period;
    return r != 0 && r <= dog.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pii dog[2];
    for (int i = 0; i < 2; ++i) {
        cin >> dog[i].first >> dog[i].second;
    }

    int arrival_time = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> arrival_time;
        cout << check_attack(arrival_time, dog[0]) + check_attack(arrival_time, dog[1]) << '\n';
    }
    return 0;
}
