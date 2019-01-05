#include <bits/stdc++.h>
using namespace std;

int arr[1010];

int shift(int curr, int piv) {
    if(piv == 0) {
        if(curr <= 2) return curr - piv;
        else return 1;
    }
    if(piv == 1) {
        if(curr == 0) return 1;
        else return curr - piv;
    }
    if(piv == 2) {
        if(curr <= 2) return piv - curr;
        else return 1;
    }
    if(piv == 3) {
        if(curr == 0) return 1;
        else return piv - curr;
    }
}

int main() {
    int n, ans = 10101, tmp;
    cin >> n;
    string str;
    for(int i = 0; i < n - 2; ++i) {
        cin >> str;
        for(int j = 0; j < 4; ++j) {
            if(str.at(j) == '0') {
                arr[i] = j;
                break;
            }
        }
    }
    for(int j = 0; j < 4; ++j) {
        tmp = 0;
        for(int i = 0; i < n - 2; ++i) tmp += shift(arr[i], j);
        ans = min(tmp, ans);
    }
    printf("%d", ans + n + 2);
    return 0;
}
