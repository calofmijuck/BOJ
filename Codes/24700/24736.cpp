#include <bits/stdc++.h>
using namespace std;

vector<int> weight = {6, 3, 2, 1, 2};

int calculate_score(vector<int>& box_score) {
    int score = 0;
    for (int i = 0; i < 5; ++i) {
        score += weight[i] * box_score[i];
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> visiting(5);
    for (int i = 0; i < 5; ++i) {
        cin >> visiting[i];
    }

    vector<int> home(5);
    for (int i = 0; i < 5; ++i) {
        cin >> home[i];
    }

    cout << calculate_score(visiting) << ' ' << calculate_score(home);
    return 0;
}
