#include <bits/stdc++.h>
#include <string>
using namespace std;

int cmp(string str1, string str2) {
    if(str1.size() != str2.size()) {
        return str1.size() < str2.size();
    }
    for(int i = 0; i < str1.size(); ++i) {
        if(str1.at(i) != str2.at(i))
            return str1.at(i) < str2.at(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<string> vec;
    string input;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> input;
        vec.push_back(input);
    }
    stable_sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < n; ++i) {
        if(i != n - 1 && vec[i + 1].compare(vec[i]) == 0) continue;
        cout << vec[i] << '\n';
    }
}
