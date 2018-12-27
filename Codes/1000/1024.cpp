#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, x, calc;
    scanf("%d %d", &n, &l);
    bool found = false;
    while(l <= 100 && !found) {
        x = (2 * n / l + 1 - l) / 2;
        calc = (2 * x + l - 1) * l / 2;
        if(n != calc || x < 0) l++;
        else found = true;
    }
    if(!found) printf("-1");
    else {
        for(int i = 0; i < l; ++i) printf("%d ", x++);
    }
    return 0;
}
