#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()
#define pb push_back


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    int ans = 0;
    if(str[0] + 1 == str[1] && str[1] + 1 == str[2] && str[2] + 1 != str[3]) {
        ans++;
    }
    for(int i = 1; i < str.size() - 1; ++i) {
        if(str[i - 1] + 1 == str[i]) continue;
        if(str[i + 2] + 1 == str[i + 3]) continue;
        if(str[i] + 1 == str[i + 1] && str[i + 1] + 1 == str[i + 2]) {
            ans++;
        }
    }
    cout << ans;
}