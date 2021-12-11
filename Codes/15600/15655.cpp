#include <bits/stdc++.h>
using namespace std;

int n, m;
int numbers[9], answer[9];

void print_sequence() {
    for (int i = 0; i < m; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

void solve(int idx, int len) {
    if (len == m) {
        print_sequence();
        return;
    }

    for (int i = idx + 1; i <= n; ++i) {
        answer[len] = numbers[i];
        solve(i, len + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers + 1, numbers + n + 1);

    solve(0, 0);
    return 0;
}
