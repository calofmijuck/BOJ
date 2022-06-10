#include <bits/stdc++.h>
using namespace std;

char grade(vector<int>& threshold, vector<int>& score) {
    if (score[2] < threshold[2]) {
        return 'E';
    }

    if (score[1] < threshold[1]) {
        if (threshold[1] / 2.0 <= score[1]) {
            return 'D';
        }

        return 'E';
    }

    if (score[0] < threshold[0]) {
        if (threshold[0] / 2.0 <= score[0]) {
            return 'B';
        }

        return 'C';
    }

    return 'A';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> threshold(3), score(3);
    for (int i = 0; i < 3; ++i) {
        cin >> threshold[i];
    }

    for (int i = 0; i < 3; ++i) {
        cin >> score[i];
    }

    cout << grade(threshold, score);
    return 0;
}
