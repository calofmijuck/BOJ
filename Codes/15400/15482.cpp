#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[3003], b[3003];
int dp[1005][1005];

bool check(int i, int j) {
	return a[i * 3] == b[j * 3] && a[i * 3 + 1] == b[j * 3 + 1] && a[i * 3 + 2] == b[j * 3 + 2];
}

int main() {
    scanf("%s %s", a, b);
	int sa = strlen(a) / 3, sb = strlen(b) / 3;
	for(int i = 1; i <= sa; ++i) {
		for(int j = 1; j <= sb; ++j) {
			if(check(i - 1, j - 1)) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d", dp[sa][sb]);
	return 0;
}
