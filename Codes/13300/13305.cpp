#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll find_min_cost(int n, vector<ll>& distance, vector<ll>& oil_cost) {
    ll min_cost = 0;
    ll min_cost_per_liter = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        min_cost_per_liter = min(min_cost_per_liter, oil_cost[i]);
        min_cost += min_cost_per_liter * distance[i];
    }
    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<ll> distance(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> distance[i];
    }
    vector<ll> oil_cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> oil_cost[i];
    }
    cout << find_min_cost(n, distance, oil_cost);
    return 0;
}
