#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<int> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    ll base = -2;
    while(n != 0) {
        int r = abs(n) % 2;
        st.push(r);
        n -= r;
        n /= base;
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}