#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, it = 1;
    scanf("%d", &n);
    vector<int> vec;
    for(int i = 1; i <= n; ++i) {
        vec.push_back(i);
        it *= i;
    }
    for(int i = 0; i < it; ++i) {
        for(int v : vec) printf("%d ", v);
        puts("");
        next_permutation(vec.begin(), vec.end());
    }

    return 0;
}
