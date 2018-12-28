#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int id[101010];
pii ant[101010];

int main() {
    int t, n, l, k, a, p;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &l, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &p, &a);
            id[i] = a;
            ant[i].second = a;
            if(a < 0) ant[i].first = p + 1;
            else ant[i].first = l - p + 1;
        }
        sort(ant, ant + n);
        int left = 0, right = 0;
        for(int i = 0; i < k - 1; ++i) {
            if(ant[i].second < 0) left++;
            else right++;
        }
        if(k <= n - 1 && ant[k - 1].first == ant[k].first) {
            printf("%d\n", min(id[left], id[n - right - 1]));
            continue;
        }
        if(k > 1 && ant[k - 1].first == ant[k - 2].first) {
            printf("%d\n", max(id[left - 1], id[n - right - 1]));
            continue;
        }
        if(ant[k - 1].second < 0) printf("%d\n", id[left]);
        else printf("%d\n", id[n - right - 1]);
    }
    return 0;
}
