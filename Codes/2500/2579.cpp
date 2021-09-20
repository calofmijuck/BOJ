#include <bits/stdc++.h>
using namespace std;

int max_score[305];

int find_max_score(int n, vector<int>& score) {
    max_score[1] = score[1];
    max_score[2] = score[1] + score[2];
    for (int i = 3; i <= n; ++i) {
        max_score[i] = max(max_score[i - 2], max_score[i - 3] + score[i - 1]) + score[i];
    }
    return max_score[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> score(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }
    cout << find_max_score(n, score);
    return 0;
}
