#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double weight;
    while (true) {
        scanf("%lf", &weight);
        if (weight < 0) {
            break;
        }

        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", weight, weight * 0.167);
    }

    return 0;
}
