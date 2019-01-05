#include <bits/stdc++.h>
using namespace std;

int height[9], sum = 0, i, j;

int main() {
    vector<int> vec;
    for(int i = 0; i < 9; ++i) {
        scanf("%d", height + i);
        sum += height[i];
    }
    bool flag;
    for(i = 0; i < 9; ++i) {
        flag = false;
        for(j = i + 1; j < 9; ++j) {
            if(sum - height[i] - height[j] == 100) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    for(int k = 0; k < 9; ++k) {
        if(k == i || k == j) continue;
        else vec.push_back(height[k]);
    }
    sort(vec.begin(), vec.end());
    for(int k = 0; k < 7; k++) printf("%d\n", vec[k]);
    return 0;
}
