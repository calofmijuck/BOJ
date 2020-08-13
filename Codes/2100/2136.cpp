#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, l, left = 0, mx = 0;
    bool fall_left = false;
    vector<pii> vec;
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(x < 0) {
            left++;
            if(mx < abs(x)) {
                fall_left = true;
                mx = abs(x);
            }
        } else {
            if(mx < l - x) {
                fall_left = false;
                mx = l - x;
            }
        }
        vec.push_back({abs(x), i + 1});
    }
    sort(vec.begin(), vec.end());
    int idx = vec[left - (fall_left ? 1 : 0)].second;
    printf("%d %d", idx, mx);
    return 0;
}