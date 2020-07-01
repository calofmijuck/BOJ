#include <stdio.h>

int han(int i) {
	if(i < 100) return 1;
	if(i == 1000) return 0;
	int hundred = i / 100;
	int ten = (i / 10) % 10;
	int one = i % 10;
	if(2 * ten == hundred + one)
		return 1;
	return 0;
}

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		ans += han(i);
	printf("%d", ans);
}