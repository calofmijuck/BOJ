#include <bits/stdc++.h>
using namespace std;

int main() {
    int cards;
    scanf("%d", &cards);

    int score = 0, prev = 0, curr;
    for (int i = 0; i < cards; ++i) {
        scanf("%d", &curr);
        if (curr - 1 != prev) {
            score += curr;
        }

        prev = curr;
    }
    printf("%d", score);
    return 0;
}
