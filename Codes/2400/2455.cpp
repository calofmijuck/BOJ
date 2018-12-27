#include <bits/stdc++.h>
using namespace std;

int main() {
    int curr = 0, in, out, mx = 0;
    for(int i = 0; i < 4; ++i) {
        scanf("%d %d", &out, &in);
        curr += in - out;
        mx = max(curr, mx);
    }
    printf("%d", mx);
    return 0;
}
