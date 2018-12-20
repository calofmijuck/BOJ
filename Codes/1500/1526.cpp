#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

void makelist(int n) {
    if(n > 1000000) return;
    vec.push_back(n);
    makelist(n * 10 + 4);
    makelist(n * 10 + 7);
}

int main() {
    int n, ans;
    scanf("%d", &n);
    makelist(4);
    makelist(7);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); ++i) {
        if(vec[i] <= n) ans = vec[i];
        else break;
    }
    printf("%d", ans);

    return 0;
}
