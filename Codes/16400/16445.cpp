#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int win = 0;
    for (int i = 0; i < n; ++i) {
        int answer;
        cin >> answer;

        if (answer != 1) {
            win++;
        }
    }

    cout << win;
    return 0;
}
