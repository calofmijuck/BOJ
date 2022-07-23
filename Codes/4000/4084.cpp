#include <bits/stdc++.h>
using namespace std;

vector<int> number(4);

void iterate() {
    vector<int> next(4);
    for (int i = 0; i < 4; ++i) {
        next[i] = abs(number[i] - number[(i + 1) % 4]);
    }
    number = next;
}

bool end_of_input() {
    bool end = true;
    for (int i = 0; i < 4; ++i) {
        end &= (number[i] == 0);
    }
    return end;
}

bool all_equal() {
    bool equal = true;
    for (int i = 0; i < 3; ++i) {
        equal &= (number[i] == number[i + 1]);
    }
    return equal;
}

int iteration_count() {
    int count = 0;
    while (true) {
        if (all_equal()) {
            return count;
        }

        iterate();
        count++;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        for (int i = 0; i < 4; ++i) {
            cin >> number[i];
        }

        if (end_of_input()) {
            break;
        }

        cout << iteration_count() << '\n';
    }
    return 0;
}
