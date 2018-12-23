#include <bits/stdc++.h>
using namespace std;



int main() {
    int t, n;
    string s1, s2;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pair<string, int>> vec;
        for(int i = 0; i < n; ++i) {
            cin >> s1 >> s2;
            bool flag = false;
            for(int j = 0; j < vec.size(); ++j) {
                string tmp = vec[j].first;
                if(tmp.compare(s2) == 0) {
                    vec[j].second++;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                vec.push_back({s2, 1});
            }
        }
        long long res = 1;
        for(int i = 0; i < vec.size(); ++i) {
            res *= vec[i].second + 1;
        }
        printf("%lld\n", res - 1);
    }
    return 0;
}
