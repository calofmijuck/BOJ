#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, d[100010], p[100010];

int main() {
	scanf("%d %d", &n, &k);
	int idx = n, tmp = 0;
    while(idx >= 0) {
        d[idx] = tmp;
		p[idx] = 1;
        idx--, tmp++;
    }
	for(int i = n + 1; i <= k + 1; i++) {
		if(i % 2 == 0) {
			if(d[i - 1] == d[i / 2])
				p[i] = p[i - 1] + p[i / 2];
			else
				p[i] = d[i - 1] < d[i / 2] ? p[i - 1] : p[i / 2];
			d[i] = min(d[i - 1], d[i / 2]) + 1;
		} else {
			d[i] = d[i - 1] + 1;
			p[i] = p[i - 1];
		}
		if(d[i - 1] == d[i] + 1)
			p[i - 1] += p[i]; 
		else if(d[i - 1] > d[i] + 1)
			p[i - 1] = p[i];
		d[i - 1] = min(d[i - 1], d[i] + 1);
	}
    printf("%d\n%d", d[k], p[k]);
	return 0;
}
