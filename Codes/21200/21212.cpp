#include <bits/stdc++.h>
using namespace std;

int main() {
    int ingredients;
    scanf("%d", &ingredients);

    int max_cakes = numeric_limits<int>::max();
    for (int i = 0; i < ingredients; ++i) {
        int per_cake, kitchen;
        scanf("%d %d", &per_cake, &kitchen);

        max_cakes = min(max_cakes, kitchen / per_cake);
    }
    printf("%d", max_cakes);
    return 0;
}
