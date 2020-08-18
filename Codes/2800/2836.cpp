#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, bool> house;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<house> vec;
    for(int i = 0; i < n; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        if(u > v) {
            vec.push_back({u, true});
            vec.push_back({v, false});
        }
    }
    sort(vec.begin(), vec.end());
    if(vec.empty()) {
        cout << m;
        return 0;
    }
    int curr = vec[0].first, prev = curr, cnt = 1;
    ll sum = curr;
    for(int i = 1; i < vec.size(); ++i) {
        curr = vec[i].first;
        if(vec[i].second) cnt--;
        else cnt++;
        if(cnt == 0) {
            sum += (ll) (curr - prev) * 3;
            if(i + 1 < vec.size()) {
                prev = vec[i + 1].first;
                sum += prev - curr;
            }
        }
    }
    sum += m - vec[vec.size() - 1].first;
    printf("%lld", sum);
    return 0;
}