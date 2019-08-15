#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    vec.resize(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end(), greater<int>());
    for(int i = 0; i < n; ++i) cout << vec[i] << '\n';
}
