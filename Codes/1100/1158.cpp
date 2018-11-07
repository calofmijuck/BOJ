#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> list(n);
    for(int i = 0; i < n; ++i) {
        list[i] = i + 1;
    }
    printf("<");
    int idx = m - 1;
    while(list.size() != 1) {
        printf("%d, ", list[idx]);
        list.erase(list.begin() + idx);
        idx += m - 1;
        if(idx >= list.size()) {
            idx %= list.size();
        }
    }
    printf("%d>", list[0]);
    return 0;
}
