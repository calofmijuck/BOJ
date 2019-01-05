#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n == 1 || n == 2 || n == 3 || n == 6) puts("0");
        else if(n == 4) puts("2");
        else puts("1");
    }
    return 0;
}
