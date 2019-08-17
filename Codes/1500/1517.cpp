#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> vec;
ll solve(int left, int right) {
    if(left == right) return 0;
    int mid = (left + right) / 2;
    ll ret = solve(left, mid) + solve(mid + 1, right);
    vector<int> tmp(right - left + 1);
    int idx = 0, st = left, ed = mid + 1;
    while(st <= mid || ed <= right) {
        if(st <= mid && (ed > right || vec[st] <= vec[ed])) tmp[idx++] = vec[st++];
        else {
            ret += mid - st + 1;
            tmp[idx++] = vec[ed++];
        }
    }
    for(int i = 0; i < tmp.size(); ++i) vec[left + i] = tmp[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
    cout << solve(0, n - 1);
}
