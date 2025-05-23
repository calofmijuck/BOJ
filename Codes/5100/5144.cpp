#include <bits/stdc++.h>
using namespace std;

void solve(int data_set) {
    int species;
    cin >> species;
    vector<int> count(species);
    vector<vector<int>> requirements(species);
    for (int i = 0; i < species; ++i) {
        cin >> count[i];
        for (int j = 0; j < i; ++j) {
            int x;
            cin >> x;
            requirements[i].push_back(x);
        }
    }

    cout << "Data Set " << data_set << ":\n";
    for (int i = 1; i < species; ++i) {
        int min_feedable = count[i];
        for (int j = 0; j < i; ++j) {
            if (requirements[i][j] == 0) {
                continue;
            }

            min_feedable = min(min_feedable, count[j] / requirements[i][j]);
        }

        count[i] = min_feedable;
        for (int j = 0; j < i; ++j) {
            count[j] -= min_feedable * requirements[i][j];
        }
    }

    for (int e : count) {
        cout << e << "\n";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        solve(i);
    }
    return 0;
}
