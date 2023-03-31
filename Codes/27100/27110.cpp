#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int chickens;
    cin >> chickens;

    int satisfied = 0;
    for (int i = 0; i < 3; ++i) {
        int soldiers;
        cin >> soldiers;
        satisfied += min(chickens, soldiers);
    }
    cout << satisfied;
    return 0;
}
