#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main() {
    int n, in;
    bool flag = true;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &in);
        vec.push_back(in);
    }
    next_permutation(vec.begin(), vec.end());
    for(int i = 0; i < vec.size() - 1; ++i) {
        if(vec[i] != vec[i + 1] - 1) {
            flag = false;
            break;
        }
    }
    if(flag) printf("-1");
    else for(int i = 0; i < vec.size(); ++i) printf("%d ", vec[i]);
    return 0;
}
