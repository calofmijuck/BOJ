#include <bits/stdc++.h>
using namespace std;

char str[5010];
int pi[5010];

int main() {
    scanf("%s", str);
    int len = strlen(str), mx = 0;
    for(int i = 0; i < len; ++i) {
        int k = 0;
        for(int j = 1; j < len - i; ++j) {
            while(k > 0 && str[i + j] != str[i + k]) k = pi[k - 1];
            if(str[i + j] == str[i + k]) pi[j] = ++k;
            else pi[j] = 0;
            mx = max(pi[j], mx);
        }
    }
    printf("%d", mx);
    return 0;
}
