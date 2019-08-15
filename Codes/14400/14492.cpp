#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<vector<bool>> A, B;
    A.resize(n), B.resize(n);
    for(int i = 0; i < n; ++i) A[i].resize(n), B[i].resize(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> x;
            if(x == 0) A[i][j] = false;
            else A[i][j] = true;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> x;
            if(x == 0) B[i][j] = false;
            else B[i][j] = true;
        }
    }
    bool curr;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            curr = false;
            for(int k = 0; k < n; ++k) {
                curr |= A[i][k] & B[k][j];
            }
            ans += (int) curr;
        }
    }
    cout << ans;
    return 0;
}
