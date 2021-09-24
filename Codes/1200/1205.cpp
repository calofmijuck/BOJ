#include <bits/stdc++.h>
using namespace std;

int find_rank(int score, int top_k, vector<int>& ranking) {
    if (top_k == (int) ranking.size() && score <= ranking.back()) {
        return -1;
    }

    int rank = ranking.size() - 1;
    while (rank >= 0 && ranking[rank] <= score) {
        rank--;
    }

    return rank + 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, score, p;
    cin >> n >> score >> p;

    if (n == 0) {
        cout << 1;
        return 0;
    }

    vector<int> ranking(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranking[i];
    }

    cout << find_rank(score, p, ranking);
    return 0;
}
