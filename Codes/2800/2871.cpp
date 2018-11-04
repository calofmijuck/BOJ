#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char str[101010], hw[50505], sk[50505];
    vector<int> vec[26];
    scanf("%d\n%s", &n, str);
    for(int i = 0; i < n; ++i) {
        char c = str[i];
        vec[c - 'a'].push_back(i);
    }
    int end = n - 1, charloc = 0, ih = 0, is = 0;
    while(n--) {
        if(n & 1) { // SK
            while(str[end] == '\0') end--;
            sk[is++] = str[end];
            vec[str[end] - 'a'].pop_back();
            str[end] = '\0';
        } else { // HW
            while(vec[charloc].empty()) ++charloc;
            int idx = vec[charloc][vec[charloc].size() - 1];
            vec[charloc].pop_back();
            hw[ih++] = str[idx];
            str[idx] = '\0';
        }
    }
    sk[is] = '\0';
    hw[ih] = '\0';
    if(strcmp(sk, hw) > 0) {
        printf("DA");
    } else {
        printf("NE");
    }
    printf("\n%s", hw);
    return 0;
}
