#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii data[55];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d %d", &data[i].first, &data[i].second);
    for(int i = 0; i < n; ++i) {
        int cnt = 1;
        for(int j = 0; j < n; ++j) {
            if(data[i].first < data[j].first && data[i].second < data[j].second) cnt++;
        }
        printf("%d ", cnt);
    }
    return 0;
}
