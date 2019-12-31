#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> house, chicken;

int bitCount(int x) {
    int ret = 0;
    while(x > 0) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}

int d(pii p1, pii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int calculate(int mark) {
    int ret = 0;
    for(pii h : house) {
        int k = mark, idx = chicken.size() - 1, dist = 0x7fffffff;
        while(k > 0 && idx >= 0) {
            if(k & 1) dist = min(dist, d(h, chicken[idx]));
            k >>= 1;
            idx--;
        }
        ret += dist;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> x;
            if(x == 1) house.push_back({i, j});
            else if(x == 2) chicken.push_back({i, j});
        }
    }
    int ans = 0x7fffffff;
    int limit = 1 << chicken.size();
    for(int i = 1; i < limit; ++i) {
        if(bitCount(i) != m) continue;
        ans = min(ans, calculate(i));
    }
    cout << ans;
    return 0;
}
