#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, int q) {
    long long running_total = 0;
    int current = 0;

    vector<long long> ans(n);

    int student;
    for (int i = 0; i < n; ++i) {
        cin >> student;

        if (student == k) {
            current = 0;
        } else {
            current += 1;
        }

        running_total += current;
        ans[i] = running_total;
    }

    int query;
    for (int i = 0; i < q; ++i) {
        cin >> query;
        cout << ans[query - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    solve(n, k, q);
    return 0;
}
