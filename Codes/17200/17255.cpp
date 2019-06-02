#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;

ll solve(int st, int ed) {
    if(st == ed) return 1;
    string left = str.substr(st, ed - st);
    string right = str.substr(st + 1, ed - st);
    if(!left.compare(right)) return solve(st, ed - 1);
    else return solve(st + 1, ed) + solve(st, ed - 1);
}

int main() {
    cin >> str;
    printf("%lld", solve(0, str.size() - 1));
    return 0;
}
