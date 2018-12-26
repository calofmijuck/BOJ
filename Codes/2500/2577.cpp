#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main() {
    int a, b, c, prod;
    scanf("%d %d %d", &a, &b, &c);
    prod = a * b * c;
    while(prod > 0) {
        cnt[prod % 10]++;
        prod /= 10;
    }
    for(int i = 0; i < 10; ++i) printf("%d\n", cnt[i]);
    return 0;
}
