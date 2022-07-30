#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> people(4);
    for (int i = 0; i < 4; ++i) {
        cin >> people[i];
    }

    int x, y, r;
    cin >> x >> y >> r;

    int answer = 0;
    for (int i = 0; i < 4; ++i) {
        if (people[i] == x) {
            answer = i + 1;
        }
    }

    cout << answer;
    return 0;
}
