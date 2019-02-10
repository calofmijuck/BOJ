#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main() {
    int n;
    scanf("%d", &n);
    while(n > 0) {
        st.push(n % 9);
        n /= 9;
    }
    while(!st.empty()) {
        printf("%d", st.top());
        st.pop();
    }
    return 0;
}
