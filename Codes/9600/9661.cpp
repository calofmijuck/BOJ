#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    int r = n % 5;
    if(r == 0 || r == 2) {
        printf("CY");
    } else printf("SK");
}
