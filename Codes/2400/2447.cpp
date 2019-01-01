#include <cstdio>
#include <cstring>

char ans[2187][2187];

void fill(int x, int y, int num) {
	if(num == 1) {
		ans[x][y] = '*';
		return;
	}
	int div = num / 3;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(i == 1 && j == 1);
			else fill(x + i * div, y + j * div, div);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	memset(ans, ' ', sizeof(ans));
	fill(0, 0, n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) printf("%c", ans[i][j]);
        puts("");
	}
}
