#include <bits/stdc++.h>
using namespace std;

int cnt[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
    string a, b;
    queue<int> res;
    cin >> a >> b;
    for(int i = 0; i < a.size(); ++i) {
        res.push(cnt[a.at(i) - 'A']);
        res.push(cnt[b.at(i) - 'A']);
    }
    int len = 2 * a.size(), tmp1, tmp2;
    while(len != 2) {
        tmp1 = res.front();
        res.pop();
        for(int i = 0; i < len - 1; ++i) {
            tmp2 = res.front();
            res.pop();
            res.push((tmp1 + tmp2) % 10);
            tmp1 = tmp2;
        }
        len = res.size();
    }
    tmp1 = res.front();
    res.pop();
    tmp2 = res.front();
    printf("%02d", 10 * tmp1 + tmp2);
    return 0;
}
