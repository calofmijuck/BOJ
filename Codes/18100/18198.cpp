#include <bits/stdc++.h>
using namespace std;

char find_winner(string& record) {
    int score[2] = {0, 0};
    for (int i = 0; i < (int) record.size(); i += 2) {
        char team = record[i];
        int point = record[i + 1] - '0';

        score[team - 'A'] += point;

        if (score[0] >= 11 and score[0] - score[1] >= 2) {
            return 'A';
        } else if (score[1] >= 11 and score[1] - score[0] >= 2) {
            return 'B';
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string record;
    cin >> record;

    cout << find_winner(record);
    return 0;
}
