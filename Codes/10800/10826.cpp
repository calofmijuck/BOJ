#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> &x, vector<int> &y) {
    vector<int> ret;
    int curr = 0;
    for(int i = 0; i < x.size(); ++i) {
        if(curr == i) {
            ret.push_back(x[i]);
            curr++;
        }
    }
    for(int i = 0; i < y.size(); ++i) {
        if(curr == i) {
            ret.push_back(y[i]);
            curr++;
        } else {
            int k = i;
            ret[i] += y[i];
            while(ret[k] >= 10) {
                if(curr == k + 1) {
                    ret.push_back(ret[k] / 10);
                    curr++;
                } else ret[k + 1] += ret[k] / 10;
                ret[k] %= 10;
                k++;
            }
        }
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a[2];
    a[0].push_back(0); a[1].push_back(1);
    for(int i = 2; i <= n; ++i) a[i % 2] = add(a[i % 2], a[1 - i % 2]);
    for(int i = (int) a[n % 2].size() - 1; i >= 0; --i) printf("%d", a[n % 2][i]);
    return 0;
}
