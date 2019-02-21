#include <bits/stdc++.h>
using namespace std;

int weight[100000];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &weight[i]);
    sort(weight, weight + n);
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(max < (n - i) * weight[i]) max = (n - i) * weight[i];
    }
    printf("%d", max);
    return 0;
}
