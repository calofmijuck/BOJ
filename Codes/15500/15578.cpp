#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(int n, int k, int m) {
    ll place = m / k;
    ll q = place / (2 * n - 2);

    vector<int> members(n);
    members[0] = q * k;
    members[n - 1] = q * k;
    for (int i = 1; i <= n - 2; ++i) {
        members[i] = 2 * q * k;
    }

    ll remaining = m - (2 * n - 2) * q * k;
    int idx = 0;
    int direction = 1;
    while (remaining != 0) {
        if (remaining < k) {
            members[idx] += remaining;
            remaining = 0;
            break;
        }

        members[idx] += k;
        remaining -= k;
        idx += direction;
        if (idx == n) {
            idx = n - 2;
            direction = -1;
        }

        if (idx == -1) {
            idx = 1;
            direction = 1;
        }
    }

    for (int e : members) {
        printf("%d ", e);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, m;
    cin >> n >> k >> m;
    solve(n, k, m);

    return 0;
}
