#include <bits/stdc++.h>
using namespace std;

bool han[1010];
int ans[1010];

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 99) {
        printf("%d", n);
        return 0;
    }
    int curr = 99;
    for(int i = 100; i < 1000; ++i) {
        string str = to_string(i);
        if(str.at(1) - str.at(0) == str.at(2) - str.at(1)) {
            han[i] = true;
            curr++;
        }
        ans[i] = curr;
    }
    ans[1000] = curr;
    printf("%d", ans[n]);
    return 0;
}
