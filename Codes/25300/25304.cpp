#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cost;
    int total_count;
    cin >> cost >> total_count;
    while (total_count--) {
        int value, count;
        cin >> value >> count;
        cost -= value * count;
    }

    cout << (cost == 0 ? "Yes" : "No");
    return 0;
}
