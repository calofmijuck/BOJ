#include <bits/stdc++.h>
using namespace std;

int arr[1000010], p[1000010];
vector<int> vec;

void process(int i) {
    int e = arr[i];
    if(vec.empty() || vec[vec.size() - 1] < e) {
        vec.push_back(e);
        p[i] = vec.size() - 1;
    } else {
        auto idx = lower_bound(vec.begin(), vec.end(), e);
        *idx = e;
        p[i] = idx - vec.begin();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        process(i);
    }
    cout << vec.size() << '\n';
    return 0;
}