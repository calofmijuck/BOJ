#include <bits/stdc++.h>
using namespace std;

#define MAX 0x3f3f3f3f

int cache[51][51][51];

bool check_last_input(int a, int b, int c) {
    return a == -1 && b == -1 && c == -1;
}

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    int &ret = cache[a][b][c];
    if (ret != MAX) {
        return ret;
    }

    if (a > 20 || b > 20 || c > 20) {
        return ret = w(20, 20, 20);
    } else if (a < b && b < c) {
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}

void print_w(int a, int b, int c, int value) {
    printf("w(%d, %d, %d) = %d\n", a, b, c, value);
}

int main() {
    memset(cache, 0x3f, sizeof(cache));

    int a, b, c;
    while (true) {
        scanf("%d %d %d", &a, &b, &c);
        if (check_last_input(a, b, c)) {
            break;
        }

        int value = w(a, b, c);
        print_w(a, b, c, value);
    }
    return 0;
}
