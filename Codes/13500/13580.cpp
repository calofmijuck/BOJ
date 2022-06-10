#include <bits/stdc++.h>
using namespace std;

bool can_return(vector<int>& year) {
    return year[0] == year[1] or year[1] == year[2] or year[0] + year[1] == year[2];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> year(3);
    for (int i = 0; i < 3; ++i) {
        cin >> year[i];
    }

    sort(begin(year), end(year));

    if (can_return(year)) {
        cout << "S";
    } else {
        cout << "N";
    }
    return 0;
}
