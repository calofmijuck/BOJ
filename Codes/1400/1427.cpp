#include <bits/stdc++.h>
using namespace std;

int bucket[10];

int main() {
    char str[20];
    scanf("%s", str);
    int i = 0;
    while(1) {
        if(str[i] == 0) break;
        ++bucket[str[i] & 0xF];
        ++i;
    }
    for(int i = 9; i >= 0; --i) {
        for(int j = 0; j < bucket[i]; ++j) printf("%d", i);
    }
    return 0;
}
