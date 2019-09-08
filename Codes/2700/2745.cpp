#include <iostream>
using namespace std;
typedef long long ll;

ll val(char c) {
    if('0' <= c && c <= '9') return c - '0';
    else return c - 'A' + 10;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    ll n;
    cin >> str >> n;
    ll res = 0;
    for(int i = 0; i < str.size(); ++i) {
        res *= n;
        res += val(str[i]);
    }
    cout << res;
}