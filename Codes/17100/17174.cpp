#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int dollar, group;
    cin >> dollar >> group;

    int count = dollar;
    int group_size = group;
    while (true) {
        int grouping = dollar / group_size;
        if (grouping == 0) {
            break;
        }

        count += grouping;
        group_size *= group;
    }

    cout << count;
    return 0;
}
