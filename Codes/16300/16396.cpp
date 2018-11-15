#include <bits/stdc++.h>
using namespace std;

bitset<10101> line;

int main() {
    int n, st, ed, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &st, &ed);
        for(int j = st; j < ed; ++j)
            line[j] = true;
    }
    for(int i = 1; i <= 10101; ++i) {
        if(line[i]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
