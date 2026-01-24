#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX_N = 200000 + 1;

vector<pair<int, int>> graph[MAX_N];
int stay[MAX_N], dist[MAX_N];
ll min_cost[MAX_N], max_cost[MAX_N];

bool visited[MAX_N];


void solve(int n) {
    memset(visited, 0, sizeof(visited));
    memset(min_cost, 0x3f, sizeof(ll) * MAX_N);
    min_cost[1] = 0;
    max_cost[1] = 0;

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto [next, cost] : graph[curr]) {
            if (dist[next] > 0 && dist[curr] + 1 != dist[next]) {
                continue;
            }

            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[curr] + 1;
                q.push(next);
            }

            min_cost[next] = min(min_cost[next], min_cost[curr] + cost + stay[next]);
            max_cost[next] = max(max_cost[next], max_cost[curr] + cost + stay[next]);
        }
    }
    cout << min_cost[0] << '\n' << max_cost[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n; ++i) {
        cin >> stay[i];
    }

    int v, w, f;
    for (int i = 0; i < m; ++i) {
        cin >> v >> w >> f;

        // set to last node
        if (w == 1) {
            w--;
        }

        graph[v].emplace_back(w, f);
    }

    solve(n);
    return 0;
}
