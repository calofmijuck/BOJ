#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, j, curr = 0, input, ans = 0;
    scanf("%d %d", &n, &m);
    vector<int> deq(n);
    for(int i = 0; i < n; ++i) deq[i] = i;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &input);
        input--;
        if(input == deq[curr]) deq.erase(deq.begin() + curr);
        else {
            for(j = 0; j < deq.size(); ++j) {
                if(input == deq[j]) break;
            }
            ans += min(abs(j - curr),  (int) deq.size() - abs(j - curr));
            deq.erase(deq.begin() + j);
            curr = j;
        }
        if(curr > deq.size() - 1) curr = 0;
    }
    printf("%d", ans);
    return 0;
}
