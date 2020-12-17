#include <bits/stdc++.h>
using namespace std;

int value(string str) {
    int idx, cnt = 1;
    if (str.size() == 2 || str.size() == 1) {
        if (str.at(0) == '(')
            return 2;
        else
            return 3;
    }
    if (str.length() == 0) 
        return 0;
    if (str.at(0) == '(') {
        for (int i = 1; i < (int)str.size(); ++i) {
            if (str.at(i) == '(') 
                cnt++;
            else if (str.at(i) == ')') 
                cnt--;
            if (cnt == 0) {
                idx = i;
                break;
            }
        }
        return 2 * (value(str.substr(1, idx - 1)) + !(idx - 1)) + value(str.substr(idx + 1));
    } else {
        for (int i = 1; i < (int)str.size(); ++i) {
            if (str.at(i) == '[') 
                cnt++;
            else if (str.at(i) == ']') 
                cnt--;
            if (cnt == 0) {
                idx = i;
                break;
            }
        }
        return 3 * (value(str.substr(1, idx - 1)) + !(idx - 1)) + value(str.substr(idx + 1));
    }
}

int main() {
    string str;
    stack<char> st;
    cin >> str;
    for (int i = 0; i < (int)str.size(); ++i) {
        char c = str.at(i);
        if (c == '(' || c == '[') {
            st.push(c);
            continue;
        } else if (st.empty()) {
            printf("0");
            return 0;
        } else {
            char top = st.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[')) {
                st.pop();
            } else {
                printf("0");
                return 0;
            }
        }
    }
    if (!st.empty()) {
        printf("0");
        return 0;
    }
    printf("%d", value(str));
    return 0;
}
