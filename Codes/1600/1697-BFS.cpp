#include <bits/stdc++.h>
using namespace std;

int n, k, ans, xmin = 0, xmax = 100000;
queue<int> q;

bool visited[100010];
int minpath[100010];

bool checkBound(int x) {
    if(xmin <= x && x <= xmax) {
        return true;
    } else {
        return false;
    }
}

void BFS(int n) {
    q.push(n);
    visited[n] = true;
    while(!q.empty()) {
        int curr = q.front();
        if(curr == k) {
            return;
        }
        q.pop();
        if(checkBound(curr - 1) && !visited[curr - 1]) {
            q.push(curr - 1);
            visited[curr - 1] = true;
            minpath[curr - 1] = minpath[curr] + 1;
        }
        if(checkBound(curr + 1) && !visited[curr + 1]) {
            q.push(curr + 1);
            visited[curr + 1] = true;
            minpath[curr + 1] = minpath[curr] + 1;
        }
        if(checkBound(2 * curr) && !visited[2 * curr]) {
            q.push(2 * curr);
            visited[2 * curr] = true;
            minpath[2 * curr] = minpath[curr] + 1;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    BFS(n);
    printf("%d", minpath[k]);
    return 0;
}
