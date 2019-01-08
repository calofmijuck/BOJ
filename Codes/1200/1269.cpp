#include <bits/stdc++.h>
using namespace std;

bitset<101010101> table;

int main() {
    int a, b, in;
    scanf("%d %d", &a, &b);
    for(int i = 0; i < a; ++i) {
        scanf("%d", &in);
        table[in] = 1;
    }
    int ans = a;
    for(int j = 0; j < b; ++j) {
        scanf("%d", &in);
        if(table[in]) ans--;
        else ans++;
    }
    printf("%d", ans);
    return 0;
}
