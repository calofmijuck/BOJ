#include <bits/stdc++.h>
using namespace std;

int elements[1000];

int score(int n) {
    int result = 0;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int solve() {
    int max_score = 0;
    for (int i = 1; i <= 999; ++i) {
        if (elements[i] == 0) {
            continue;
        }

        for (int j = 1; j <= 999; ++j) {
            if (elements[j] == 0) {
                continue;
            }

            if (i == j && elements[i] <= 1) {
                continue;
            }

            max_score = max(max_score, score(i * j));
        }
    }

    return max_score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        elements[x] += 1;
    }

    cout << solve();
    return 0;
}
