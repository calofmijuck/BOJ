#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_CARD = 1000000;

bool exists[MAX_CARD + 1];
int card[MAX_N];
int score[MAX_CARD + 1];

void calculate_scores() {
    for (int i = 1; i <= MAX_CARD; ++i) {
        if (!exists[i]) {
            continue;
        }

        for (int j = 2 * i; j <= MAX_CARD; j += i) {
            if (exists[j]) {
                score[i] += 1;
                score[j] -= 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> card[i];
        exists[card[i]] = true;
    }

    calculate_scores();

    for (int i = 0; i < n; ++i) {
        cout << score[card[i]] << ' ';
    }
    return 0;
}
