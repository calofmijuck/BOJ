#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) && a > 0) {
        if(a % b == 0) printf("multiple\n");
        else if(b % a == 0) printf("factor\n");
        else printf("neither\n");
    }
    return 0;
}
