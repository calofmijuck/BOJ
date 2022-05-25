#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

typedef struct {
    pii sides;
    int index;
} pedestal;

bool compare_pedestal(pedestal& p1, pedestal& p2) {
    return p1.sides < p2.sides;
}

map<int, int> find_assignment(vector<pedestal>& pedestals, vector<pii>& vase) {
    if (vase.size() > pedestals.size()) {
        return map<int, int>();
    }

    sort(begin(pedestals), end(pedestals), compare_pedestal);
    sort(begin(vase), end(vase));

    map<int, int> assignment;

    int pedestal_index = 0, index = 0;
    while (index < (int) vase.size()) {
        if (pedestal_index >= (int) pedestals.size()) {
            break;
        }

        auto [diameter, vase_index] = vase[index];
        pii sides = pedestals[pedestal_index].sides;
        if (sides.first != diameter && sides.second != diameter) {
            pedestal_index++;
            continue;
        }

        assignment[vase_index] = pedestals[pedestal_index].index;
        pedestal_index++;
        index++;
    }
    return assignment;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int p, v;
    cin >> p >> v;

    vector<pedestal> pedestals(p);
    for (int i = 0; i < p; ++i) {
        pii& side = pedestals[i].sides;
        cin >> side.first >> side.second;
        if (side.first > side.second) {
            swap(side.first, side.second);
        }

        pedestals[i].index = i + 1;
    }

    vector<pii> vase(v);
    for (int i = 0; i < v; ++i) {
        cin >> vase[i].first;
        vase[i].second = i;
    }

    map<int, int> assignment = find_assignment(pedestals, vase);
    if ((int) assignment.size() != v) {
        cout << "impossible";
        return 0;
    }

    for (auto [vase_index, pedestal_index] : assignment) {
        cout << pedestal_index << '\n';
    }
    return 0;
}
