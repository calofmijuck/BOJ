#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> v, vector<int> w) {
    int add = 0, sub = 0;
    for(int i = 0; i < 26; ++i) {
        int d = v[i] - w[i];
        if(abs(d) >= 2) return false;
        else if(d == 1) {
            add++;
            if(add > 1) return false;
        } else if(d == -1) {
            sub++;
            if(sub > 1) return false;
        }
    }
    // if(add == 1 && sub == 1) return true;
    return true;
}

int main() {
    int n, ans = 0;
    string word;
    cin >> n >> word;
    vector<int> v(26, 0);
    for(int i = 0; i < word.size(); ++i) v[word[i] - 'A']++;
    for(int i = 0; i < n - 1; ++i) {
        string str;
        cin >> str;
        vector<int> w(26, 0);
        for(int i = 0; i < str.size(); ++i) w[str[i] - 'A']++;
        if(cmp(v, w)) ans++;
    }
    cout << ans;
}