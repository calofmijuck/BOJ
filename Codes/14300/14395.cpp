#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, string> pls;

ll s, t;
queue<pair<ll, string>> q;
string s1, s2, s3, ans, tmp;
char op[4] = {'*', '+', '-', '/'};
pls curr;

bool BFS() {
    while(!q.empty()) {
        pls curr = q.front();
        q.pop();
        if(curr.first == t) {
            ans = curr.second;
            return true;
        }
        if(t >= curr.first * curr.first && curr.first * curr.first > 1) {
            tmp = curr.second;
            tmp.push_back('*');
            q.push({curr.first * curr.first, tmp});
        }
        if(t >= curr.first * 2 && curr.first > 0) {
            tmp = curr.second;
            tmp.push_back('+');
            q.push({curr.first * 2, tmp});
        }
    }
    return false;
}

int main() {
    scanf("%lld %lld", &s, &t);
    if(s == t) {
        printf("0");
    } else if(t == 0) {
        printf("-");
    } else {
        s1.push_back('*');
        s2.push_back('+');
        s3.push_back('/');
        if(s * s <= t)
            q.push({s * s, s1});
        if(s + s <= t)
            q.push({s + s, s2});
        q.push({1, s3});
        if(BFS()) cout << ans;
        else cout << "-1";
    }
    return 0;
}
