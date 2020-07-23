#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s;
    t = s;
	for(int i = 0; i < 4; ++i) s.push_back('0');
	stack<char> st;
	int i = s.size() - 1, j = t.size() - 1, c = 0;
	while(j >= 0) {
		int x = c + (s[i--] - '0') + (t[j--] - '0');
		st.push(x % 2);
		c = x / 2;
	}
	while(i >= 0) {
		int x = c + (s[i--] - '0');
		st.push(x % 2);
		c = x / 2;
	}
	if(c > 0) st.push(1);
	while(!st.empty()) {
		cout << (char) ('0' + st.top());
		st.pop();
	}
    return 0;
}