#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, c;
    stack<char> st;
    scanf("%d %d", &n, &b);
    while(n > 0) {
        c = n % b;
        n /= b;
        if(c < 10) st.push('0' + c);
        else st.push('A' + c - 10);
    }
    while(!st.empty()) {
        printf("%c", st.top());
        st.pop();
    }
    return 0;
}
