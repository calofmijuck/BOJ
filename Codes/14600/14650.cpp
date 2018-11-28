#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) printf("0");
    else printf("%.0lf", 2 * pow(3, n - 2));
    return 0;
}
