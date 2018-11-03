#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, a = 1, b = 0, tmp; cin >> k;
    for(int i = 0; i < k; i++) {
        tmp = a + b;
        a = b;
        b = tmp;
    }
    printf("%d %d\n", a, b);
}
