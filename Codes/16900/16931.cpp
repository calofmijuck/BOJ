#include <cstdio>
#include <algorithm>
using namespace std;

int arr[101][101];

int main() {
	int n, m, sum = 0, lap = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &arr[i][j]);
			sum += arr[i][j];
			lap += arr[i][j] - 1;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(j != m - 1) lap += min(arr[i][j], arr[i][j + 1]);
			if(i != n - 1) lap += min(arr[i][j], arr[i + 1][j]);
		}
	}
	printf("%d", 6 * sum - 2 * lap);
	return 0;
}
