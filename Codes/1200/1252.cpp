#include <bits/stdc++.h>
using namespace std;

char ans[85];
stack<int> n1, n2, st;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); ++i) n1.push(s1.at(i) - '0');
    for(int i = 0; i < s2.size(); ++i) n2.push(s2.at(i) - '0');
    int x, y, c = 0, tmp;
    while(!n1.empty() && !n2.empty()) {
        x = n1.top(), y = n2.top();
        n1.pop(), n2.pop();
        tmp = (x + y + c) % 2;
        c = (x + y + c) / 2;
        st.push(tmp);
    }
    while(!n1.empty()) {
        x = n1.top(), n1.pop();
        tmp = (x + c) % 2;
        c = (x + c) / 2;
        st.push(tmp);
    }
    while(!n2.empty()) {
        y = n2.top(), n2.pop();
        tmp = (y + c) % 2;
        c = (y + c) / 2;
        st.push(tmp);
    }
    st.push(c);
    int size = st.size();
    for(int i = 0; i < size; ++i) {
        ans[i] = st.top() + '0';
        st.pop();
    }
    int k = 0;
    while(ans[k] == '0') k++;
    if(k == size) printf("0");
    else {
        for(int i = k; i < size; ++i) printf("%c", ans[i]);
    }
    return 0;
}
