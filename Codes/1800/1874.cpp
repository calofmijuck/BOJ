#include <bits/stdc++.h>
using namespace std;

int num[101010];

int main() {
    int n, input, idx = 0;
    stack<int> st;
    vector<char> ans;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", num + i);
    for(int i = 1; i <= n; ++i) {
        st.push(i);
        ans.push_back('+');
        while(!st.empty() && st.top() == num[idx]) {
            ++idx;
            st.pop();
            ans.push_back('-');
        }
    }
    if(!st.empty()) printf("NO");
    else {
        for(int i = 0; i < ans.size(); ++i) printf("%c\n", ans[i]);
    }
    return 0;
}
