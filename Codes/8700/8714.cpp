#include <bits/stdc++.h>
using namespace std;

int main() {
    int coins;
    scanf("%d", &coins);

    int heads = 0, tails = 0, coin;
    for (int i = 0; i < coins; ++i) {
        scanf("%d", &coin);
        if (coin == 0) {
            tails++;
        } else {
            heads++;
        }
    }

    printf("%d", min(heads, tails));
    return 0;
}
