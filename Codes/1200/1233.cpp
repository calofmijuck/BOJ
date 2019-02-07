#include <bits/stdc++.h>
using namespace std;

int die[16001];

int main() {
    int a, b, c, mx = 0, arg;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            for(int k = 1; k <= c; ++k) die[i + j + k] += 1;
        }
    }
    for(int i = 1; i <= a * b * c; ++i) {
        if(mx < die[i]) {
            arg = i;
            mx = die[i];
        }
    }
    printf("%d", arg);
    return 0;
}
