#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int total_snow, ball;
    cin >> total_snow >> ball;
    total_snow *= 1000;
    ball *= 1000;

    int ball_top = 7 * ball;
    int ball_middle = 7 * ball / 2;
    int ball_bottom = 7 * ball / 4;

    if (ball_top <= total_snow) {
        cout << ball_top;
    } else if (ball_middle <= total_snow) {
        cout << ball_middle;
    } else if (ball_bottom <= total_snow) {
        cout << ball_bottom;
    } else {
        cout << 0;
    }
    return 0;
}
