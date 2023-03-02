#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int rules;
    cin >> rules;

    string dummy;
    getline(cin, dummy);

    vector<string> rule_list(rules);
    for (int i = 0; i < rules; ++i) {
        getline(cin, rule_list[i]);
    }

    int queries;
    cin >> queries;
    for (int i = 0; i < queries; ++i) {
        int query;
        cin >> query;

        if (1 <= query && query <= rules) {
            cout << "Rule " << query << ": " << rule_list[query - 1] << '\n';
        } else {
            cout << "Rule " << query << ": " << "No such rule\n";
        }
    }
    return 0;
}
