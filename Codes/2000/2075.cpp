#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, in;
    scanf("%d", &n);
    priority_queue<int> pq;
    for(int i = 0; i < n * n; ++i) {
        scanf("%d", &in);
        pq.push(-in);
        if(pq.size() > n) pq.pop();
    }
    printf("%d", -pq.top());
    return 0;
}
