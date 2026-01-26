#include <bits/stdc++.h>
using namespace std;

int n, m;
int lengths[100000];

bool check(int mid) {
    int disks = 1, remaining = mid;
    for (int i = 0; i < n; ++i) {
        if (lengths[i] > mid) {
            return false;
        }

        if (lengths[i] > remaining) {
            disks++;
            remaining = mid;
        }
        remaining -= lengths[i];
    }

    return disks <= m;
}

int solve() {
    int left = 1, right = 10000 * n;
    while (left < right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    cout << solve();
    return 0;
}
