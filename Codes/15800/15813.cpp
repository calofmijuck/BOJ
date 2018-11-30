#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sum = 0;
    string str;
    cin >> n >> str;
    for(int i = 0; i < str.size(); ++i)
        sum += str.at(i) - 'A' + 1;
    cout << sum;
    return 0;
}
