#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define MAX_N 100100
#define B_SIZE 42

int bucket_size = 2800, n, q, arr[MAX_N];
vector<int> bucket[B_SIZE];

void update(int i, int v) {
    --i;
    int x = arr[i];
    int bucket_idx = i / bucket_size;
    auto it = lower_bound(bucket[bucket_idx].begin(), bucket[bucket_idx].end(), x);
    bucket[bucket_idx].erase(it);
    arr[i] = v;
    it = lower_bound(bucket[bucket_idx].begin(), bucket[bucket_idx].end(), v);
    bucket[bucket_idx].insert(it, v);
}

int count(int left, int right, int k) {
    int ret = 0;
    for(int i = left; i <= right; ++i) {
        if(arr[i] > k)
            ++ret;
    }
    return ret;
}

int query(int i, int j, int k) {
    --i, --j;
    int ans = 0;
    int left_bucket = (i + bucket_size) / bucket_size * bucket_size;
    int right_bucket = j / bucket_size * bucket_size;

    if(left_bucket < right_bucket) {
        ans += count(i, left_bucket - 1, k);
        ans += count(right_bucket, j, k);

        int st = left_bucket / bucket_size;
        int ed = right_bucket / bucket_size;
        for(int idx = st; idx < ed; ++idx) {
            auto cnt = upper_bound(bucket[idx].begin(), bucket[idx].end(), k);
            ans += bucket[idx].end() - cnt;
        }
    } else {
        ans += count(i, j, k);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        bucket[i / bucket_size].push_back(arr[i]);
    }
    for(int i = 0; i < B_SIZE; ++i)
        sort(bucket[i].begin(), bucket[i].end());
    
    // query
    cin >> q;
    while(q--) {
        int op, v, i, j, k;
        cin >> op;
        if(op == 1) {
            cin >> i >> v;
            update(i, v);
        } else {
            cin >> i >> j >> k;
            cout << query(i, j, k) << '\n';
        }
    }
    return 0;
}