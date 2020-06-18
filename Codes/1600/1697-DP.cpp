#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, d[100001];

int main() {
	scanf("%d %d", &n, &k);
    int idx = n, tmp = 0;
    while(idx >= 0) {
        d[idx] = tmp;
        idx--, tmp++;
    }
	for(int i = n + 1; i <= k + 1; i++) {
		if(i % 2 == 0) d[i] = min(d[i - 1], d[i / 2]) + 1;
		else d[i] = d[i - 1] + 1;
		d[i - 1] = min(d[i - 1], d[i] + 1);
	}
    printf("%d", d[k]);
	return 0;
}
