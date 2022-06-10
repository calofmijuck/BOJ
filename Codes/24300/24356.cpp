#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t1, m1, t2, m2;
    cin >> t1 >> m1 >> t2 >> m2;

    int start_minutes = 60 * t1 + m1;
    int end_minutes = 60 * t2 + m2;
    if (end_minutes < start_minutes) {
        end_minutes += 24 * 60;
    }

    int diff = end_minutes - start_minutes;
    cout << diff << ' ' << diff / 30;
    return 0;
}
