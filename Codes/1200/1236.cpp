#include <bits/stdc++.h>
using namespace std;

int check_horizontal(vector<string>& castle) {
    int count = 0;
    for (string line : castle) {
        bool guard_exists = false;
        for (char c : line) {
            guard_exists |= (c == 'X');
        }

        if (!guard_exists) {
            count++;
        }
    }
    return count;
}

int check_vertical(vector<string>& castle) {
    int count = 0;
    for (int j = 0; j < (int) castle[0].size(); ++j) {
        bool guard_exists = false;
        for (int i = 0; i < (int) castle.size(); ++i) {
            guard_exists |= (castle[i][j] == 'X');
        }

        if (!guard_exists) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<string> castle(n);
    for (int i = 0; i < n; ++i) {
        cin >> castle[i];
    }

    cout << max(check_horizontal(castle), check_vertical(castle));
    return 0;
}
