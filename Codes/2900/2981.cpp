#include <bits/stdc++.h>
using namespace std;

int arr[101];

int gcd(int a, int b) {
    if(!a) return b;
    else return gcd(b % a, a);
}

int main() {
    int n, g;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    sort(arr, arr + n);
    g = arr[1] - arr[0];
    for(int i = 2; i < n; ++i) g = gcd(g, arr[i] - arr[i - 1]);
    vector<int> ans;
    for(int i = 1; i * i <= g; ++i) {
        if(!(g % i)) {
            ans.push_back(i);
            if(i * i != g) ans.push_back(g / i);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 1; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}
