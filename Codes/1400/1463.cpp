#include <bits/stdc++.h>
using namespace std;

int dp(int x) {
	if (x < 2) return 0;
	int f = dp(x / 3) + (x % 3) + 1;
	int s = dp(x / 2) + (x % 2) + 1;    
	return f < s ? f : s;
}

int main() {
	int n;
    scanf("%d", &n);
	printf("%d", dp(n));
}
