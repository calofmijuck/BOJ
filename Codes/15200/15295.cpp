#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int number, days;
        scanf("%d %d", &number, &days);

        printf("%d %d\n", number, days * (days + 3) / 2);
    }
    return 0;
}
