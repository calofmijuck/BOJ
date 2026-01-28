#include "stdio.h"

int n;

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }

    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve(int num, int position) {
    if (position == n) {
        printf("%d\n", num);
        return;
    }

    for (int digit = 1; digit <= 9; ++digit) {
        int candidate = num * 10 + digit;
        if (is_prime(candidate)) {
            solve(candidate, position + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    solve(0, 0);
    return 0;
}
