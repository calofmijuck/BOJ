#include <bits/stdc++.h>
using namespace std;

int arr[15];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    vector<int> vec;
    vec.push_back(n);
    for(int i = n - 2; i >= 0; --i) {
        int cnt = 0;
        for(int j = 0; j < vec.size(); ++j) {
            if(arr[i] == 0) {
                vec.insert(vec.begin(), i + 1);
                break;
            }
            if(vec[j] > i + 1) cnt++;
            if(cnt == arr[i]) {
                vec.insert(vec.begin() + cnt, i + 1);
                break;
            }
        }
    }
    for(int i = 0; i < vec.size(); ++i) printf("%d ", vec[i]);
    return 0;
}
