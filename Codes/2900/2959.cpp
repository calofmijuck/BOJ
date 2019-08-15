#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x;
    vector<int> vec;
    for(int i = 0; i < 4; ++i) {
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    cout << vec[0] * vec[2];
}
