#include <bits/stdc++.h>
using namespace std;

int main() {
    int score[6];
    for (int i = 0; i < 6; ++i) {
        cin >> score[i];
    }
    sort(score, score + 4);
    cout << score[1] + score[2] + score[3] + max(score[4], score[5]);
    return 0;
}
