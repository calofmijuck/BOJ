#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int stair, speed, walking_speed;
    cin >> stair >> speed >> walking_speed;

    double left_speed, right_speed;
    cin >> left_speed >> right_speed;

    int left, right;
    cin >> left >> right;

    double left_time = left / left_speed + stair / walking_speed;
    double right_time = right / right_speed + stair / speed;

    if (left_time < right_time) {
        cout << "friskus";
    } else {
        cout << "latmask";
    }
    return 0;
}
