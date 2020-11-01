#include <bits/stdc++.h>
using namespace std;

int arr[1010], dp[1010], p[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 0; i < n; ++i) {
        if(dp[i] == 0) {
            dp[i] = 1;
            p[i] = -1;
        }
        for(int j = 0; j < i; ++j) {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
    }
    int len = 0, idx = 0;
    for(int i = 0; i < n; ++i) {
        if(len < dp[i]) {
            len = dp[i];
            idx = i;
        }
    }
    cout << len << '\n';

    // reconstruction
    stack<int> st;
    do {
        st.push(idx);
        idx = p[idx];
    } while(idx != -1);
    while(!st.empty()) {
        int t = st.top();
        st.pop();
        cout << arr[t] << ' ';
    }
    return 0;
}