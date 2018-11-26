#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> q;
    int n, input;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str.compare("push_front") == 0) {
            cin >> input;
            q.push_front(input);
        } else if(str.compare("push_back") == 0) {
            cin >> input;
            q.push_back(input);
        } else if(str.compare("pop_front") == 0) {
            if(q.empty()) cout << "-1\n";
            else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        } else if(str.compare("pop_back") == 0) {
            if(q.empty()) cout << "-1\n";
            else {
                cout << q.back() << '\n';
                q.pop_back();
            }
        } else if(str.compare("size") == 0) {
            cout << q.size() << '\n';
        } else if(str.compare("empty") == 0) {
            cout << (int) q.empty() << '\n';
        } else if(str.compare("front") == 0) {
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        } else if(str.compare("back") == 0) {
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }
    }
    return 0;
}
