#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& sides) {
    int n = sides.size();
    sort(begin(sides), end(sides));

    for (int i = n - 3; i >= 0; --i) {
        if (sides[i] + sides[i + 1] > sides[i + 2]) {
            return sides[i] + sides[i + 1] + sides[i + 2];
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> sides(n);
    for (auto& side : sides) {
        cin >> side;
    }

    cout << solve(sides);
    return 0;
}
