#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int res = 0;
    while(n > 0) res += (n /= 5);
    printf("%d", res);
    return 0;
}
