#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    int day = ceil((double) (v - a) / (a - b));
    printf("%d", day + 1);
    return 0;
}
