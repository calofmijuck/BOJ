#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, d[100001];

int main() {
	scanf("%d %d", &n, &k);
	if(n > k) {
		printf("%d", n - k);
		return 0;
	}
	if(n == 0) d[n + 1] = 1;
	else d[n - 1] = d[n + 1] = 1;
    int idx = n - 2, tmp = 2;
    while(idx >= 0) {
        d[idx] = tmp;
        idx--, tmp++;
    }
	for(int i = n + 2; i <= k + 1; i++) {
		if(i % 2 == 0) d[i] = min(d[i - 1], d[i / 2]) + 1;
		else d[i] = d[i - 1] + 1;
		d[i - 1] = min(d[i - 1], d[i] + 1);
	}
    printf("%d", d[k]);
	return 0;
}
