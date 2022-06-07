#include <bits/stdc++.h>
using namespace std;

int calculate_score() {
    int score = 0;
    for (int i = 3; i > 0; --i) {
        int x;
        cin >> x;
        score += i * x;
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int apples = calculate_score();
    int bananas = calculate_score();

    if (apples > bananas) {
        cout << "A";
    } else if (apples < bananas) {
        cout << "B";
    } else {
        cout << "T";
    }
    return 0;
}
