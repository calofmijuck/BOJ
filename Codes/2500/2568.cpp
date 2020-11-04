#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> vec;
vector<int> arr, idx, dp;

void process(int i) {
    int e = arr[i];
    if(dp.empty() || dp[dp.size() - 1] < e) {
        dp.push_back(e);
        idx[i] = dp.size() - 1;
    } else {
        auto t = lower_bound(dp.begin(), dp.end(), e);
        *t = e;
        idx[i] = t - dp.begin();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }
    sort(vec.begin(), vec.end());

    arr.resize(n);
    idx.resize(n);
    for(int i = 0; i < n; ++i)
        arr[i] = vec[i].second;

    for(int i = 0; i < n; ++i)
        process(i);
    
    int lis = dp.size();
    int ans = n - lis;
    cout << ans << '\n';

    // reconstruct
    --lis;
    stack<int> st;
    for(int i = n - 1; i >= 0; --i) {
        if(idx[i] == lis)
            --lis;
        else
            st.push(vec[i].first);
    }
    while(!st.empty()) {
        cout << st.top() << '\n';
        st.pop();
    }
    return 0;
}