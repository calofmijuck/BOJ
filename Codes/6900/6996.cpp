#include <bits/stdc++.h>
using namespace std;

int occ1[26], occ2[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> t;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        if(s.size() != t.size()) {
            cout << s << " & " << t << " are NOT anagrams.\n";
            continue;
        }
        memset(occ1, 0, sizeof(occ1));
        memset(occ2, 0, sizeof(occ2));
        for(int j = 0; j < s.size(); j++) {
            occ1[s.at(j) - 'a']++;
            occ2[t.at(j) - 'a']++;
        }
        bool flag = true;
        for(int j = 0; j < 26; j++) {
            if(occ1[j] != occ2[j]) {
                cout << s << " & " << t << " are NOT anagrams.\n";
                flag = false;
                break;
            }
        }
        if(flag) cout << s << " & " << t << " are anagrams.\n";

    }
    return 0;
}
