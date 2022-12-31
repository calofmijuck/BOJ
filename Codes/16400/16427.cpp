#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cases, multiplier;
    cin >> cases >> multiplier;

    int max_running_time = 0;
    for (int i = 0; i < cases; ++i) {
        int running_time;
        cin >> running_time;

        max_running_time = max(max_running_time, multiplier * running_time);
    }
    cout << (max_running_time - 1) / 1000 + 1;
    return 0;
}
