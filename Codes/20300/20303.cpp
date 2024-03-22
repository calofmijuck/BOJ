#include <bits/stdc++.h>
using namespace std;

using graph = vector<vector<int>>;
using pii = pair<int, int>;

const int MAX_N = 30000;
const int MAX_K = 3000;

int candy[MAX_N + 1];
bool visited[MAX_N + 1];

int dp[MAX_N + 1][MAX_K];

graph build_graph(int vertices, int edges) {
    graph adj(vertices + 1);
    int u, v;
    for (int i = 0; i < edges; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

pii get_candies(graph& adj, int v) {
    int price = 0, weight = 0;

    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        visited[curr] = true;
        price += candy[curr];
        weight += 1;

        for (int& next : adj[curr]) {
            if (visited[next]) {
                continue;
            }

            visited[next] = true;
            q.push(next);
        }
    }
    return { price, weight };
}

vector<pii> process_relations(graph& adj) {
    vector<pii> items;
    for (int v = 1; v < (int) adj.size(); ++v) {
        if (visited[v]) {
            continue;
        }

        pii item = get_candies(adj, v);
        items.push_back(item);
    }
    return items;
}

int knapsack(vector<pii>& items, int max_weight) {
    int item_count = items.size();
    for (int i = 1; i <= item_count; ++i) {
        int price = items[i - 1].first, weight = items[i - 1].second;
        for (int w = 1; w <= max_weight; ++w) {
            if (w < weight) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight] + price);
            }
        }
    }
    return dp[item_count][max_weight];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> candy[i];
    }

    graph adj = build_graph(n, m);
    vector<pii> items = process_relations(adj);

    cout << knapsack(items, k - 1);
    return 0;
}
