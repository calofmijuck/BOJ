#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int weight, max_weight = 0;
        for (int j = 0; j < 5; ++j) {
            cin >> weight;
            max_weight = max(weight, max_weight);
        }

        cout << "Case #" << i << ": " << max_weight << '\n';
    }
    return 0;
}
