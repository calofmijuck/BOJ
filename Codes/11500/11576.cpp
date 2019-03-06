#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, m, base = 1, sum = 0, in;
    scanf("%d %d %d", &a, &b, &m);
    stack<int> st;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &in);
        st.push(in);
    }
    while(!st.empty()) {
        sum += st.top() * base;
        st.pop();
        base *= a;
    }
    while(sum > 0) {
        st.push(sum % b);
        sum /= b;
    }
    while(!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}
