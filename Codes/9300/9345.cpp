#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define INF 0x3fffffff

int dvd[101010], minBlock[1010], maxBlock[1010];
int sz;

void update(int l, int r) {
    swap(dvd[l], dvd[r]);
    minBlock[l / sz] = minBlock[r / sz] = INF;
    maxBlock[l / sz] = maxBlock[r / sz] = 0;
    for(int i = (l / sz) * sz; i < (l / sz) * sz + sz; ++i) {
        minBlock[i / sz] = min(minBlock[i / sz], dvd[i]);
        maxBlock[i / sz] = max(maxBlock[i / sz], dvd[i]);
    }
    for(int i = (r / sz) * sz; i < (r / sz) * sz + sz; ++i) {
        minBlock[i / sz] = min(minBlock[i / sz], dvd[i]);
        maxBlock[i / sz] = max(maxBlock[i / sz], dvd[i]);
    }
}

pii query(int l, int r) {
    int x = INF, y = 0;
    while(l % sz != 0 && l <= r) {
        x = min(x, dvd[l]);
        y = max(y, dvd[l]);
        l++;
    }
    while((r + 1) % sz != 0 && l <= r) {
        x = min(x, dvd[r]);
        y = max(y, dvd[r]);
        r--;
    }
    while(l <= r) {
        x = min(x, minBlock[l / sz]);
        y = max(y, maxBlock[l / sz]);
        l += sz;
    }
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, k, q, a, b;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        sz = sqrt(n);
        for(int i = 0; i <= sz; ++i) minBlock[i] = INF, maxBlock[i] = 0;
        for(int i = 0; i < n; ++i) {
            dvd[i] = i;
            minBlock[i / sz] = min(minBlock[i / sz], dvd[i]);
            maxBlock[i / sz] = max(maxBlock[i / sz], dvd[i]);
        }
        for(int i = 0; i < k; ++i) {
            cin >> q >> a >> b;
            if(q == 0) update(a, b);
            else {
                pii p = query(a, b);
                cout << ((p.first == a && p.second == b) ? "YES\n" : "NO\n");
            }
        }
    }
}