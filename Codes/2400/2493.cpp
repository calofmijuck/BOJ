#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

void solve(int n) {
    stack<pii> st;

    int height;
    for (int i = 1; i <= n; ++i) {
        cin >> height;

        while (!st.empty() && st.top().first < height) {
            st.pop();
        }

        if (st.empty()) {
            cout << "0" << ' ';
        } else {
            cout << st.top().second << ' ';
        }
        st.push({ height, i });
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    solve(n);
    return 0;
}
