#include <bits/stdc++.h>
using namespace std;

#define MAX_V 100001

typedef pair<int, int> pii;

int discover_time[MAX_V];
int discover = 0;

vector<int> adj[MAX_V];

vector<pii> bridges;

int dfs(int current, int parent) {
    discover_time[current] = ++discover;
    int ret = discover_time[current];

    for (int next : adj[current]) {
        if (next == parent) {
            continue;
        }

        if (discover_time[next] != 0) {
            ret = min(ret, discover_time[next]);
            continue;
        }

        int min_discover_time = dfs(next, current);
        if (discover_time[current] < min_discover_time) {
            bridges.push_back({min(current, next), max(current, next)});
        }
        ret = min(ret, min_discover_time);
    }
    return ret;
}

void find_bridges(int v) {
    for (int i = 1; i <= v; ++i) {
        if (discover_time[i] == 0) {
            dfs(i, 0);
        }
    }

    sort(bridges.begin(), bridges.end());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int v, e;
    cin >> v >> e;
    for (int i = 0 ; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_bridges(v);

    cout << bridges.size() << '\n';
    for (pii bridge : bridges) {
        cout << bridge.first << ' ' << bridge.second << '\n';
    }
    return 0;
}
