#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> scores(3);
    for (int i = 0; i < 3; ++i) {
        cin >> scores[i];
    }

    sort(begin(scores), end(scores));
    cout << scores[1] + scores[2];
    return 0;
}
