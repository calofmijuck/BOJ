#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    scanf("%d", &n);
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        vec.push_back({b, a});
    }
    sort(vec.begin(), vec.end());
    int ans = 0, curr = 0;
    for(int i = 0; i < n; ++i) {
        if(vec[i].second >= curr) {
            ans++;
            curr = vec[i].first;
        }
    }
    printf("%d", ans);
    return 0;
}
