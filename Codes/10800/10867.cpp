#include <bits/stdc++.h>
using namespace std;

int bucket[2001];

int main() {
    int n, in;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &in);
        bucket[in + 1000]++;
    }
    for(int i = 0; i < 2001; ++i) {
        if(bucket[i]) printf("%d ", i - 1000);
    }
    return 0;
}
