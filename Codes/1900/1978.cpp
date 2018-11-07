#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, input, ans = 0;
    bool prime;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &input);
        prime = true;
        for(int j = 2; j * j <= input; ++j) {
            if(input % j == 0) {
                prime = false;
                break;
            }
        }
        if(prime && input != 1) ans++;
    }
    printf("%d", ans);
    return 0;
}
