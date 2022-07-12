#include <bits/stdc++.h>
using namespace std;

bool end_of_input(vector<int>& birth, vector<int>& death) {
    return birth[0] == 0 and birth[1] == 0 and death[0] == 0 and death[1] == 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> birth(2), death(2);
    while (true) {
        cin >> birth[0] >> birth[1];
        cin >> death[0] >> death[1];
        if (end_of_input(birth, death)) {
            break;
        }

        int max = death[1] - birth[0];
        int min = death[0] - birth[1];
        cout << min << ' ' << max << '\n';
    }
    return 0;
}
