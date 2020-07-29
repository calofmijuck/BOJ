#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, two = 0, one = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        two += x / 2;
        if(x & 1) one++;
    }
    if(two == one) puts("YES");
    else if(one > two) puts("NO");
    else {
        int d = two - one;
        if(d % 3 == 0) puts("YES");
        else puts("NO");
    }
    return 0;
}