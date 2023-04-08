#include <bits/stdc++.h>
using namespace std;

const int RIGHT = 0;
const int LEFT = 1;

int digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int prev_direction = RIGHT;
    while (true) {
        int instruction;
        cin >> instruction;

        if (instruction == 99999) {
            break;
        }

        int two_digit_sum = digit_sum(instruction / 1000);

        int direction = RIGHT;
        if (two_digit_sum == 0) {
            direction = prev_direction;
        } else if (two_digit_sum % 2 == 0) {
            direction = RIGHT;
        } else {
            direction = LEFT;
        }


        if (direction == RIGHT) {
            cout << "right";
        } else {
            cout << "left";
        }
        cout << ' ' << instruction % 1000 << '\n';

        prev_direction = direction;
    }
    return 0;
}
