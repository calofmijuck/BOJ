#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

deque<pii> dq;

int main() {
    int n, l, in;
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= n; ++i) {
        while(dq.size() && dq.front().second <= i - l) dq.pop_front();
        scanf("%d", &in);
        while(dq.size() && dq.back().first >= in) dq.pop_back();
        dq.push_back({in, i});
        printf("%d ", dq.front().first);
    }
    return 0;
}
