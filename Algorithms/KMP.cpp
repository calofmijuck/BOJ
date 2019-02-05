// KMP string matching algorithm

#include <bits/stdc++.h>
using namespace std;

// Preprocess the pattern and find the failure function
vector<int> preprocess(string p){
    int m = p.size();
    vector<int> fail(m);
    fail[0] = 0;
    int j = 0;
    for(int i = 1; i < m; ++i){
        while(j > 0 && p[i] != p[j]) j = fail[j - 1];
        if(p[i] == p[j]) {
            fail[i] = j + 1;
            j++;
        } else fail[i] = 0;
    }
    return fail;
}

vector<int> kmp(string s, string p){
    auto fail = preprocess(p);
    vector<int> ans;
    int n = s.size(), m = p.size();
    int j = 0;
    for(int i = 0; i < n; ++i){
        while(j > 0 && s[i] != p[j]) j = fail[j - 1];
        if(s[i] == p[j]){
            if(j == m - 1){
                ans.push_back(i - m + 1);
                j = fail[j];
            } else j++;
        }
    }
    return ans;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    vector<int> res = kmp(str1, str2);
    for(int e : res) printf("%d ", e);
    return 0;
}
