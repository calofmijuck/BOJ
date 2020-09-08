#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
    int ret = 0;
    while(n > 0) {
        ret = (10 * ret) + (n % 10);
        n /= 10;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int s, t;
        scanf("%d %d", &s, &t);
        int rev_sum = reverse(s) + reverse(t);
        printf("%d\n", reverse(rev_sum));
    }
    return 0;
}