#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int count_black(set<pii>& grid, int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (grid.count({ x + dx, y + dy }) == 1) {
                count++;
            }
        }
    }
    return count;
}

void solve(int h, int w, int n) {
    set<pii> grid;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        grid.insert({ x, y });
    }

    vector<ll> answer(10);

    set<pii> visited;
    for (const auto& black : grid) {
        auto& [x, y] = black;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (nx < 2 || nx > h - 1 || ny < 2 || ny > w - 1) {
                    continue;
                }

                if (visited.count({ nx, ny }) == 1) {
                    continue;
                }

                visited.insert({ nx, ny });
                int count = count_black(grid, nx, ny);

                assert(count != 0);
                answer[count]++;
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= 9; ++i) {
        sum += answer[i];
    }

    answer[0] = ll(w - 2) * (h - 2) - sum;
    for (int i = 0; i <= 9; ++i) {
        cout << answer[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int h, w, n;
    cin >> h >> w >> n;
    solve(h, w, n);
    return 0;
}
