#include <bits/stdc++.h>
using namespace std;

int main() {
    int current, target;
    scanf("%d %d", &current, &target);

    int diff = target - current;
    if (diff > 180) {
        diff -= 360;
    } else if (diff <= -180) {
        diff += 360;
    }
    printf("%d", diff);
    return 0;
}
