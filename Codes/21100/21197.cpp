#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int pressed;
    cin >> pressed;

    bool running = false;
    int display = 0, start = 0;
    for (int i = 0; i < pressed; ++i) {
        int t;
        cin >> t;

        running ^= 1;
        if (running) {
            start = t;
        } else {
            display += t - start;
            start = 0;
        }
    }

    if (running) {
        cout << "still running";
    } else {
        cout << display;
    }
    return 0;
}
