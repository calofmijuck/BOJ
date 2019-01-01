#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, x, y;
vector<pii> vec;

int d(pii p1, pii p2) {
    int x = p2.first - p1.first, y = p2.second - p1.second;
    return x * x + y * y;
}

int solve(int st, int ed) {
    if(ed - st == 1) {
        return d(vec[st], vec[ed]);
    } else if(ed - st == 2) {
        int tmp = d(vec[st], vec[st + 1]);
        tmp = min(tmp, d(vec[st], vec[st + 2]));
        return min(tmp, d(vec[st + 1], vec[st + 2]));
    }
    int mid = (st + ed) / 2;
    int ret = min(solve(st, mid), solve(mid + 1, ed));
    vector<pii> tmp;
    tmp.push_back({vec[mid].second, vec[mid].first});
    for(int i = mid - 1; i >= st; --i) {
        if(vec[mid].first - vec[i].first >= ret) break;
        tmp.push_back({vec[i].second, vec[i].first});
    }
    for(int i = mid + 1; i <= ed; ++i) {
        if(vec[i].first - vec[mid].first >= ret) break;
        tmp.push_back({vec[i].second, vec[i].first});
    }
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size(); ++i) {
        for(int j = i + 1; j < tmp.size(); ++j) {
            if(d({tmp[i].first, 0}, {tmp[j].first, 0}) >= ret) break;
            ret = min(ret, d(tmp[i], tmp[j]));
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    printf("%d", solve(0, n - 1));

    return 0;
}
