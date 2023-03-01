#include <bits/stdc++.h>
using namespace std;

int winning_candidate() {
    int candidates, regions;
    cin >> candidates >> regions;

    vector<int> votes(candidates, 0);
    for (int i = 0; i < regions; ++i) {
        for (int j = 0; j < candidates; ++j) {
            int vote;
            cin >> vote;
            votes[j] += vote;
        }
    }

    int arg_max = 0, max = 0;
    for (int i = 0; i < (int) votes.size(); i++) {
        if (votes[i] > max) {
            arg_max = i;
            max = votes[i];
        }
    }
    return arg_max + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cout << winning_candidate() << '\n';
    }
    return 0;
}
