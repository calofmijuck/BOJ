#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, current, maximum;
    cin >> n >> current >> maximum;

    for (int i = 0; i < n; ++i) {
        int next;
        cin >> next;

        if (next > maximum) {
            cout << "BBTV: Dollar reached " << next << " Oshloobs, A record!\n";
            maximum = next;
        } else if (next < current) {
            int diff = current - next;
            cout << "NTV: Dollar dropped by " << diff << " Oshloobs\n";
        }
        current = next;
    }
    return 0;
}
