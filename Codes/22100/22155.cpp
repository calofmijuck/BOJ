#include <bits/stdc++.h>
using namespace std;

bool is_simple(int conditionals, int loops) {
    return (conditionals <= 1 and loops <= 2) or (conditionals <= 2 and loops <= 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int conditionals, loops;
        cin >> conditionals >> loops;

        if (is_simple(conditionals, loops)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
