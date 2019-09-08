#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int A[10], B[10], a = 0, b = 0;
    for(int i = 0; i < 10; ++i) cin >> A[i];
    for(int i = 0; i < 10; ++i) cin >> B[i];
    for(int i = 0; i < 10; ++i) {
        if(A[i] > B[i]) a++;
        else if(B[i] > A[i]) b++;
    }
    if(a > b) cout << "A";
    else if(a < b) cout << "B";
    else cout << "D";
}