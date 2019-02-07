#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, b;
    scanf("%d %d", &r, &b);
    for(int i = 1; i * i <= b; ++i) {
        if(b % i == 0 && r == 4 + 2 * (i + b / i)) {
            printf("%d %d", b / i + 2, i + 2);
            return 0;
        }
    }
    return 0;
}
