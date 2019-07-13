#include <cstdio>
#include <stack>
using namespace std;

int arr[1010101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    stack<int> st, ans;
    int i = n - 1;
    while(i > -1) {
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if(st.empty()) ans.push(-1);
        else ans.push(st.top());
        st.push(arr[i]);
        i--;
    }
    while(!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
}
