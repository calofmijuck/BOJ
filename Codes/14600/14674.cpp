#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct game_info {
    int id;
    int cost;
    int rating;
};

bool compare_game(game_info& g, game_info& other) {
    ll left = (ll) g.rating * other.cost;
    ll right = (ll) g.cost * other.rating;
    if (left != right) {
        return left > right;
    }

    if (g.cost != other.cost) {
        return g.cost < other.cost;
    }

    return g.id < other.id;
}

void solve(int games, int buy) {
    vector<game_info> infos(games);
    for (int i = 0; i < games; ++i) {
        cin >> infos[i].id >> infos[i].cost >> infos[i].rating;
    }

    sort(begin(infos), end(infos), compare_game);

    for (int i = 0; i < buy; ++i) {
        cout << infos[i].id << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    solve(n, k);
    return 0;
}
