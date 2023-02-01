#include <bits/stdc++.h>
using namespace std;

int main() {
    int at_bats;
    scanf("%d", &at_bats);

    int total = 0, count = 0;
    for (int i = 0; i < at_bats; ++i) {
        int run;
        scanf("%d", &run);

        if (run == -1) {
            continue;
        }

        total += run;
        count++;
    }

    printf("%.4lf", double(total) / count);
    return 0;
}
