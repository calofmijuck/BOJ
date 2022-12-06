#include <bits/stdc++.h>
using namespace std;

bool counted[201];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int largest = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        largest = max(largest, x);
        counted[x] = true;
    }

    bool missing = false;
    for (int i = 1; i <= largest; ++i) {
        if (counted[i]) {
            continue;
        }

        missing = true;
        cout << i << '\n';
    }

    if (!missing) {
        cout << "good job";
    }
    return 0;
}
