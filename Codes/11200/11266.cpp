#include <bits/stdc++.h>
using namespace std;

#define MAX_V 10001

int discover_time[MAX_V];
int discover = 0;

bool is_articulation_point[MAX_V];

vector<int> adj[MAX_V];

int dfs(int current, bool is_root) {
    discover_time[current] = ++discover;
    int ret = discover_time[current];

    int child = 0;
    for (int next : adj[current]) {
        if (discover_time[next] != 0) {
            ret = min(ret, discover_time[next]);
            continue;
        }

        child++;
        int min_discover_time = dfs(next, false);
        if (!is_root && discover_time[current] <= min_discover_time) {
            is_articulation_point[current] = true;
        }
        ret = min(ret, min_discover_time);
    }

    if (is_root && child > 1) {
        is_articulation_point[current] = true;
    }
    return ret;
}

vector<int> find_articulation_points(int v) {
    for (int i = 1; i <= v; ++i) {
        if (discover_time[i] == 0) {
            dfs(i, true);
        }
    }

    vector<int> articulation_points;
    for (int i = 1; i <= v; ++i) {
        if (is_articulation_point[i]) {
            articulation_points.push_back(i);
        }
    }
    return articulation_points;
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

    vector<int> articulation_points = find_articulation_points(v);
    cout << articulation_points.size() << '\n';
    for (int vertex : articulation_points) {
        cout << vertex << ' ';
    }
    return 0;
}
