#include <bits/stdc++.h>
using namespace std;

vector<int> preprocess(string p){
    int m = p.size();
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    for(int i = 1; i < m; ++i){
        while(j > 0 && p[i] != p[j]) j = pi[j - 1];
        if(p[i] == p[j]) {
            pi[i] = j + 1;
            j++;
        } else pi[i] = 0;
    }
    return pi;
}

int main() {
    string str;
    while(cin >> str) {
        int len = str.size();
        if(len == 1 && str[0] == '.') break;
        auto pi = preprocess(str);
        if(pi[len - 1] == 0) {
            puts("1");
            continue;
        }
        int k = len - pi[len - 1];
        if(len % k == 0) printf("%d\n", len / k);
        else puts("1");
    }
    return 0;
}
