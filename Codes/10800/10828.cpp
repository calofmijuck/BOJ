#include <bits/stdc++.h>
using namespace std;

#define LENGTH 10000

class Stack {
private:
    int data[LENGTH];
    int idx;
public:
    Stack() : idx(-1) {}

    void push(int num) {
        ++idx;
        data[idx] = num;
    }

    int pop() {
        if(idx == -1) return -1;
        int ret = data[idx];
        --idx;
        return ret;
    }

    int top() {
        if(idx == -1) return -1;
        return data[idx];
    }

    int size() {
        return idx + 1;
    }

    int empty() {
        if(idx == -1) return 1;
        else return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    string str;
    cin >> n;
    Stack st;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        switch(str.at(0)) {
            case 'p':
                if(str.at(1) == 'u') {
                    cin >> input;
                    st.push(input);
                }
                else cout << st.pop() << '\n';
                break;
            case 't':
                cout << st.top() << '\n';
                break;
            case 's':
                cout << st.size() << '\n';
                break;
            case 'e':
                cout << st.empty() << '\n';
                break;
            default:;
        }
    }
    return 0;
}
