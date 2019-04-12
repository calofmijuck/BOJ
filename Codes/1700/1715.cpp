#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, curr, next;
    priority_queue<int, vector<int>, greater<int>> pq;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &curr);
        pq.push(curr);
    }
    curr = pq.top();
    pq.pop();
    while(!pq.empty()) {
        next = pq.top();
        pq.pop();
        sum += curr + next;
        pq.push(curr + next);
        curr = pq.top();
        pq.pop();
    }
    printf("%d", sum);
    return 0;
}
