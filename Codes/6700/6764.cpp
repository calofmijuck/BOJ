#include <bits/stdc++.h>
using namespace std;

int depth[4];

bool fish_rising() {
    for (int i = 0; i < 3; ++i) {
        if (depth[i] >= depth[i + 1]) {
            return false;
        }
    }
    return true;
}

bool fish_diving() {
    for (int i = 0; i < 3; ++i) {
        if (depth[i] <= depth[i + 1]) {
            return false;
        }
    }
    return true;
}

bool constant_depth() {
    for (int i = 0; i < 3; ++i) {
        if (depth[i] != depth[i + 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 4; ++i) {
        cin >> depth[i];
    }

    if (fish_rising()) {
        cout << "Fish Rising";
    } else if (fish_diving()) {
        cout << "Fish Diving";
    } else if (constant_depth()) {
        cout << "Fish At Constant Depth";
    } else {
        cout << "No Fish";
    }
    return 0;
}
