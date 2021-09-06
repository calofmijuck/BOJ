#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int speed_limit, speed;
    cin >> speed_limit >> speed;
    if (speed_limit >= speed) {
        cout << "Congratulations, you are within the speed limit!";
        return 0;
    }
    int diff = speed - speed_limit;
    int fine = 0;
    if (1 <= diff && diff <= 20) {
        fine = 100;
    } else if (21 <= diff && diff <= 30) {
        fine = 270;
    } else {
        fine = 500;
    }
    cout << "You are speeding and your fine is $" << fine << ".";
    return 0;
}
