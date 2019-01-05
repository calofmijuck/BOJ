#include <bits/stdc++.h>
using namespace std;

int l;
char str[120];
bool show[120];
pair<char, int> arr[120];

void printstr() {
    for(int i = 0; i < l; ++i) if(show[i]) printf("%c", str[i]);
    puts("");
}

void solve(int st, int ed) {
    if(st > ed) return;
    if(st == ed) {
        show[st] = true;
        printstr();
        return;
    }
    for(int i = st; i <= ed; ++i) arr[i] = {str[i], i};
    sort(arr + st, arr + ed + 1);
    int idx = arr[st].second;
    show[idx] = true;
    printstr();
    solve(idx + 1, ed);
    solve(st, idx - 1);
}

int main() {
    scanf("%s", str);
    l = strlen(str);
    solve(0, l - 1);
    return 0;
}
