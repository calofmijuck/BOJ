#include <bits/stdc++.h>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string ans[7] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};

int main() {
    int d, m;
    scanf("%d %d", &d, &m);
    for(int i = 1; i <= m - 1; ++i) d += month[i];
    d %= 7;
    cout << ans[d];
    return 0;
}
