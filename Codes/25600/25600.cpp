#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int max_score = 0, score;
    for (int i = 0; i < n; ++i) {
        int a, d, g;
        cin >> a >> d >> g;

        score = a * (d + g);
        if (a == d + g) {
            score *= 2;
        }

        max_score = max(max_score, score);
    }
    cout << max_score;
    return 0;
}
