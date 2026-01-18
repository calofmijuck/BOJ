#include <bits/stdc++.h>
using namespace std;

const int INF = 0x70000000;

int solve(int target, int cities) {
    vector<int> min_cost(1200, INF);
    min_cost[0] = 0;

    int customer, cost;
    for (int i = 0; i < cities; ++i) {
        cin >> cost >> customer;

        for (int j = customer; j < (int) min_cost.size(); j++) {
            min_cost[j] = min(min_cost[j], min_cost[j - customer] + cost);
        }
    }

    int answer = min_cost[target];
    for (int i = target + 1; i < (int) min_cost.size(); ++i) {
        answer = min(answer, min_cost[i]);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int c, n;
    cin >> c >> n;

    cout << solve(c, n);
    return 0;
}
