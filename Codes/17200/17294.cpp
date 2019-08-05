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
    string str;
    cin >> str;
    for(int i = 1; i < str.size() - 1; ++i) {
        if(2 *  (str[i] - '0') != (str[i - 1] - '0') + (str[i + 1] - '0')) {
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
            return 0;
        }
    }
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}