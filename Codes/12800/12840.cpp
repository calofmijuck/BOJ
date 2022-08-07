#include <bits/stdc++.h>
using namespace std;

const int TOTAL_SECONDS = 24 * 60 * 60;

void print_value(int value) {
    int hour = value / 3600;
    int minute = (value / 60) % 60;
    int second = value % 60;

    cout << hour << ' ' << minute << ' ' << second << '\n';
}

int calculate(int current, int value, bool add) {
    int result = (current + (add ? 1 : -1) * value) % TOTAL_SECONDS;
    return (result < 0) ? result + TOTAL_SECONDS : result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int hour, minute, second;
    cin >> hour >> minute >> second;

    int current = (minute + 60 * hour) * 60 + second;

    int queries;
    cin >> queries;
    for (int i = 0; i < queries; ++i) {
        int op, value;
        cin >> op;

        if (op == 3) {
            print_value(current);
        } else {
            cin >> value;
            current = calculate(current, value, op == 1);
        }
    }
    return 0;
}
