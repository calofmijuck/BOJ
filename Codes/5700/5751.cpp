#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int toss;
    while (true) {
        cin >> toss;
        if (toss == 0) {
            break;
        }

        int curr;
        int heads = 0, tails = 0;
        for (int i = 0; i < toss; ++i) {
            cin >> curr;
            if (curr == 0) {
                heads++;
            } else {
                tails++;
            }
        }

        cout << "Mary won " << heads << " times and John won " << tails << " times\n";
    }
    return 0;
}
