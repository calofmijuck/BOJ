#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<int>& vec, int n) {
    sort(vec.begin(), vec.end());
    int idx = lower_bound(vec.begin(), vec.end(), n) - vec.begin();

    if (vec[idx] == n) {
        return 0;
    }

    int left = (idx == 0) ? 1 : vec[idx - 1] + 1;
    int right = vec[idx] - 1;
    return (ll) (n - left + 1) * (right - n + 1) - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l, x, n;
    cin >> l;
    vector<int> vec;
    for (int i = 0; i < l; ++i) {
        cin >> x;
        vec.push_back(x);
    }
    
    cin >> n;
    cout << solve(vec, n);
    return 0;
}
