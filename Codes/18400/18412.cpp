#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int length, start, end;
    cin >> length >> start >> end;

    string s;
    cin >> s;

    reverse(begin(s) + start - 1, begin(s) + end);

    cout << s;
    return 0;
}
