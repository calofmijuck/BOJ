#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

int cnt[501], lastrank[501];
pii arr[501];

int main() {
    int t, n, m, in, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &in);
            cnt[in] = i;
            lastrank[in] = i + 1;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            if(lastrank[a] < lastrank[b]) {
                cnt[a]++;
                cnt[b]--;
            } else {
                cnt[a]--;
                cnt[b]++;
            }
        }
        for(int i = 1; i <= n; ++i) arr[i - 1] = make_pair(cnt[i], i);
        sort(arr, arr + n);
        bool flag = true;
        for(int i = 0; i < n; ++i) {
            if(arr[i].first != i) {
                flag = false;
                break;
            }
        }
        if(!flag) printf("IMPOSSIBLE");
        else for(int i = 0; i < n; ++i) printf("%d ", arr[i].second);
        puts("");
    }
    return 0;
}
