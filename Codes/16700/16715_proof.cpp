#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii sol1(int n) {
    int idx = 0, max = 0, tmp, sum;
    for(int i = 2; i <= n; ++i) {
        tmp = n, sum = 0;
        while(tmp > 0) { sum += tmp % i, tmp /= i; }
        if(max < sum) { max = sum, idx = i; }
    }
    return {max, idx};
}

pii sol2(int n) {
    return {n % (n / 2 + 1) + 1, n / 2 + 1};
}

int main() {
    for(int i = 2; i <= 100000; ++i) {
        pii one = sol1(i);
        pii two = sol2(i);
        if(one.first != two.first || one.second != two.second) {
            printf("Origin: %d %d, Modi: %d %d\n", one.first, one.second, two.first, two.second);
        }
    }
    return 0;
}
