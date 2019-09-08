#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int candidate[3][3];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        for(int j = 0; j < 3; ++j) {
            cin >> x;
            if(x == 3) candidate[j][2]++;
            else if(x == 2) candidate[j][1]++;
            else candidate[j][0]++;
        }
    }
    pii score[3] = {{0, 1}, {0, 2}, {0, 3}};
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= 3; ++j) score[i].first += j * candidate[i][j - 1];
    }
    sort(score, score + 3);
    if(score[2].first != score[1].first) {
        cout << score[2].second << ' ' << score[2].first;
    } else {
        int c1 = score[2].second, c2 = score[1].second;
        if(candidate[c1 - 1][2] > candidate[c2 - 1][2]) {
            cout << c1 << ' ' << score[2].first;
        } else if(candidate[c1 - 1][2] < candidate[c2 - 1][2]) {
            cout << c2 << ' ' << score[1].first;
        } else {
            if(candidate[c1 - 1][1] > candidate[c2 - 1][1]) {
                cout << c1 << ' ' << score[2].first;
            } else if(candidate[c1 - 1][1] < candidate[c2 - 1][1]) {
                cout << c2 << ' ' << score[1].first;
            } else {
                cout << 0 << ' ' << score[2].first;
            }
        }
    }
}