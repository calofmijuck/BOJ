#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> score(6);
    while (true) {
        for (int i = 0; i < 6; ++i) {
            cin >> score[i];
        }

        sort(begin(score), end(score));
        if (score[0] == 0 && score[5] == 0) {
            break;
        }

        int sum = 0;
        for (int i = 1; i < 5; ++i) {
            sum += score[i];
        }

        cout << sum / 4.0 << '\n';
    }
    return 0;
}
