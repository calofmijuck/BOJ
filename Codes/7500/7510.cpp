#include <bits/stdc++.h>
using namespace std;

bool is_right_triangle(vector<int>& sides) {
    return (long long) sides[0] * sides[0] + sides[1] * sides[1] == (long long) sides[2] * sides[2];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> sides(3);

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        cin >> sides[0] >> sides[1] >> sides[2];
        sort(begin(sides), end(sides));

        bool right = is_right_triangle(sides);
        cout << "Scenario #" << i << ":\n" << (right ? "yes" : "no") << "\n\n";
    }
    return 0;
}
