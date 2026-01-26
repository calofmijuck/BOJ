#include <bits/stdc++.h>
using namespace std;

int solve(int h, int w) {
    int water = 0, curr;
    stack<pair<int, int>> st;
    for (int i = 0; i < w; ++i) {
        cin >> curr;

        while (!st.empty() && curr > st.top().first) {
            auto [top, _] = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }

            int left = st.top().first;
            int distance = i - st.top().second - 1;
            int height = min(left, curr) - top;
            water += distance * height;
        }

        st.emplace(curr, i);
    }
    return water;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int h, w;
    cin >> h >> w;

    cout << solve(h, w);
    return 0;
}
