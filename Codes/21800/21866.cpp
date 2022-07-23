#include <bits/stdc++.h>
using namespace std;

const int max_size = 9;
vector<int> max_score = { 100, 100, 200, 200, 300, 300, 400, 400, 500 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int total = 0, score;
    for (int i = 0; i < max_size; ++i) {
        cin >> score;
        if (score > max_score[i]) {
            cout << "hacker";
            return 0;
        }

        total += score;
    }

    cout << (total >= 100 ? "draw" : "none");
    return 0;
}
