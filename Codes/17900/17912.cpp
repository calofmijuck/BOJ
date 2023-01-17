#include <bits/stdc++.h>
using namespace std;

int main() {
    int days;
    scanf("%d", &days);

    int min = numeric_limits<int>::max(), min_index = -1;
    for (int i = 0; i < days; ++i) {
        int junk;
        scanf("%d", &junk);

        if (junk < min) {
            min = junk;
            min_index = i;
        }
    }
    printf("%d", min_index);
    return 0;
}
