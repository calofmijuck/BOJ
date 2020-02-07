#include <bits/stdc++.h>
using namespace std;

stack<string> num;
stack<char> op;

int getPre(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

void calculate() {
    string s = num.top(); num.pop();
    string t = num.top(); num.pop();
    num.push(t + s + op.top());
    op.pop();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); ++i) {
        char c = str[i];
        if('A' <= c && c <= 'Z') {
            num.push(string(1, c));
        } else if(c == '(') {
            op.push(c);
        } else if(c == ')') {
            while(op.top() != '(')
                calculate();
            op.pop();
        } else {
            if(!op.empty()) {
                while(!op.empty() && getPre(c) <= getPre(op.top()))
                    calculate();
            }
            op.push(c);
        } 
    }
    while(!op.empty())
        calculate();
    cout << num.top();
    return 0;
}
