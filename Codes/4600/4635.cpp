#include <bits/stdc++.h>
using namespace std;

int calculate(int n) {
    int total = 0, prev = 0;
    for (int i = 0; i < n; ++i) {
        int speed, time_taken;
        cin >> speed >> time_taken;

        total += speed * (time_taken - prev);
        prev = time_taken;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }

        cout << calculate(n) << " miles\n";
    }
    return 0;
}
