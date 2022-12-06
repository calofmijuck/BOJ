#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

vector<pii> swaps;
vector<int> guess;

int simulate(int initial) {
    int score = 0;
    int curr = initial;
    for (int i = 0; i < (int) guess.size(); ++i) {
        auto& [left, right] = swaps[i];
        if (left == curr) {
            curr = right;
        } else if (right == curr) {
            curr = left;
        }

        if (guess[i] == curr) {
            score++;
        }
    }
    return score;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    guess.resize(n);
    swaps.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> swaps[i].first >> swaps[i].second >> guess[i];
    }

    int score = 0;
    for (int i = 1; i <= 3; ++i) {
        int simulate_result = simulate(i);
        score = max(score, simulate_result);
    }
    cout << score;

    return 0;
}
