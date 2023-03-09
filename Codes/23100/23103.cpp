#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int distance = 0;
    pair<int, int> curr, next;
    for (int i = 0; i < n; ++i) {
        cin >> next.first >> next.second;

        if (i != 0) {
            distance += abs(next.first - curr.first) + abs(next.second - curr.second);
        }

        curr = next;
    }
    cout << distance;
    return 0;
}
