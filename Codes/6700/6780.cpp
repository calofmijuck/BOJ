#include <bits/stdc++.h>
using namespace std;

int t[2];

int main() {
    scanf("%d %d", t, t + 1);

    int length = 2, next;
    while (true) {
        length++;

        next = t[0] - t[1];
        if (next > t[1]) {
            break;
        }

        t[0] = t[1];
        t[1] = next;
    }
    printf("%d", length);
    return 0;
}
