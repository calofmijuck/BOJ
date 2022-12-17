#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string mbti;
    int n;

    cin >> mbti >> n;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (mbti == s) {
            count++;
        }
    }

    cout << count;
    return 0;
}
