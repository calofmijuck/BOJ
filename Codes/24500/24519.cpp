#include <bits/stdc++.h>
using namespace std;

const int MAX = 0x7FFF0000;
const int MAX_N = 18;

int n, m;
int graph[MAX_N][MAX_N];
pair<int, int> bottleneck[MAX_N][1 << MAX_N];

int btsp(int visited, int here) {
    if (visited + 1 == (1 << n)) {
        if (graph[here][0] == 0) {
            return MAX;
        }

        return graph[here][0];
    }

    pair<int, int>& current = bottleneck[here][visited];
    if (current.first != 0) {
        return current.first;
    }

    current.first = MAX;
    for (int next = 0; next < n; ++next) {
        if (graph[here][next] == 0 || (visited & (1 << next)) != 0) {
            continue;
        }

        int candidate = max(graph[here][next], btsp(visited | (1 << next), next));

        if (candidate < current.first) {
            current.first = candidate;
            current.second = next;
        }
    }

    return current.first;
}

void path_construction() {
    int visited = 1, here = 0;
    for (int i = 0; i < n; ++i) {
        cout << here + 1 << ' ';
        here = bottleneck[here][visited].second;
        visited |= (1 << here);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    int u, v, c;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        graph[u - 1][v - 1] = c;
    }

    int ans = btsp(1, 0);
    if (ans == MAX) {
        cout << -1;
        return 0;
    }

    cout << ans << '\n';
    path_construction();

    return 0;
}
