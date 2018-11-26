#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main() {
    int t, n, m, input, ans;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        vec.resize(n);
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &input);
            vec[i] = input;
            q.push(input);
        }
        sort(vec.begin(), vec.end());
        ans = 0;
        while(1) {
            int mx = vec.back();
            int top = q.front();
            q.pop();
            if(m == 0) {
                if(mx == top) {
                    ans++;
                    printf("%d\n", ans);
                    break;
                } else {
                    q.push(top);
                    m += vec.size() - 1;
                }
            } else {
                m--;
                if(mx == top) {
                    vec.pop_back();
                    ans++;
                } else q.push(top);
            }
        }
    }
    return 0;
}
