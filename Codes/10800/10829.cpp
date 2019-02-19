#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<ll> st;

int main() {
    ll n;
    scanf("%lld", &n);
    while(n > 0) {
        st.push(n % 2);
        n >>= 1;
    }
    while(!st.empty()) {
        printf("%lld", st.top());
        st.pop();
    }
    return 0;
}
