#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct move_info {
    int l;
    int r;
    int cost;
};

ll solve(int n, int m, vector<int>& seq, vector<move_info>& moves) {
    map<vector<int>, int> min_cost;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    pq.push({ 0, seq });
    min_cost[seq] = 0;

    while (!pq.empty()) {
        auto [cost, here] = pq.top();
        pq.pop();

        if (min_cost.count(here) != 0 && min_cost[here] < cost) {
            continue;
        }

        for (auto& [l, r, move_cost] : moves) {
            swap(here[l], here[r]);
            if (min_cost.count(here) == 0 || cost + move_cost < min_cost[here]) {
                min_cost[here] = cost + move_cost;
                pq.push({ min_cost[here], here });
            }
            swap(here[l], here[r]);
        }
    }

    // find sorted
    sort(begin(seq), end(seq));
    return (min_cost.count(seq) == 0) ? -1 : min_cost[seq];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> seq(n);
    for (int& e : seq) {
        cin >> e;
    }

    cin >> m;
    vector<move_info> moves(m);
    for (auto& e : moves) {
        cin >> e.l >> e.r >> e.cost;
        e.l--;
        e.r--;
    }

    cout << solve(n, m, seq, moves);
    return 0;
}
