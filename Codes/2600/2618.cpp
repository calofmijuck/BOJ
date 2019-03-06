#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii event[1010], track[1010][1010];
int dp[1010][1010], ans[1010];

int d(pii a, pii b) {
    return (int) abs(a.first - b.first) + (int) abs(a.second - b.second);
}

void trace(int idx, pii curr) {
    if(curr == make_pair(0, 0)) return;
    pii prev = track[curr.first][curr.second];
    if(curr.first == idx) {
        while(idx > curr.second) ans[idx--] = 1;
    } else {
        while(idx > curr.first) ans[idx--] = 2;
    }
    trace(idx, prev);
}

int main() {
    int n, w, x, y, sum = 0;
    scanf("%d %d", &n, &w);
    for(int i = 1; i <= w; ++i) scanf("%d %d", &event[i].first, &event[i].second);
    dp[1][0] = d({1, 1}, event[1]);
    dp[0][1] = d({n, n}, event[1]);
    for(int i = 2; i <= w; ++i) {
        dp[i][i - 1] = dp[0][i - 1] + d({1, 1}, event[i]);
        track[i][i - 1] = {0, i - 1};
        for(int j = 1; j < i - 1; ++j) {
            if(dp[i][i - 1] > dp[j][i - 1] + d(event[j], event[i])) {
                dp[i][i - 1] = dp[j][i - 1] + d(event[j], event[i]);
                track[i][i - 1] = {j, i - 1};
            }
        }
        dp[i - 1][i] = dp[i - 1][0] + d({n, n}, event[i]);
        track[i - 1][i] = {i - 1, 0};
        for(int j = 1; j < i - 1; ++j) {
            if(dp[i - 1][i] > dp[i - 1][j] + d(event[i], event[j])) {
                dp[i - 1][i] = dp[i - 1][j] + d(event[i], event[j]);
                track[i - 1][i] = {i - 1, j};
            }
        }
        for(int j = 0; j < i - 1; ++j) {
            dp[j][i] = dp[j][i - 1] + d(event[i - 1], event[i]);
            dp[i][j] = dp[i - 1][j] + d(event[i - 1], event[i]);
            track[j][i] = {j, i - 1};
            track[i][j] = {i - 1, j};
        }
    }
    int mx = 0x7FFFFFFF;
    pii fin;
    for(int i = 0; i < w; ++i) {
        if(mx > dp[w][i]) {
            mx = dp[w][i];
            fin = {w, i};
        }
        if(mx > dp[i][w]) {
            mx = dp[i][w];
            fin = {i, w};
        }
    }
    trace(w, fin);
    printf("%d\n", mx);
    for(int i = 1; i <= w; ++i) printf("%d\n", ans[i]);
    return 0;
}
