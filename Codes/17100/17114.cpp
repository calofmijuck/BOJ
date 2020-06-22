#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int r, c, t, room[55][55], tmp[55][55];
pii clean;

inline bool check(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> r >> c >> t;
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			cin >> room[i][j];
			if(room[i][j] == -1)
				clean = {i, j};
		}
	}
	for(int k = 0; k < t; ++k) {
		memset(tmp, 0, sizeof(tmp));
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				if(room[i][j] >= 5) {
					int d = room[i][j] / 5;
					for(int l = 0; l < 4; ++l) {
						int nx = i + dx[l], ny = j + dy[l];
						if(!check(nx, ny) || room[nx][ny] == -1) continue;
						tmp[nx][ny] += d;
						room[i][j] -= d;
					}
				}
				tmp[i][j] += room[i][j];
			}
		}
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j)
				room[i][j] = tmp[i][j];
		}
		int x = clean.first - 1, y = clean.second + 1;
		int prev = 0, next;
		while(y < c - 1) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			y++;
		}
		while(x > 0) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			x--;
		}
		while(y > 0) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			y--;
		}
		while(x < clean.first - 1) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			x++;
		}
		while(y < clean.second) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			y++;
		}
		x = clean.first, y = clean.second + 1;
		prev = 0;
		while(y < c - 1) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			y++;
		}
		while(x < r - 1) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			x++;
		}
		while(y > 0) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			y--;
		}
		while(x > clean.first) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			x--;
		}
		while(y < clean.second) {
			next = room[x][y];
			room[x][y] = prev;
			prev = next;
			y++;
		}
	}
	int ans = 0;
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j)
			ans += room[i][j];
	}
	cout << ans + 2;
	return 0;
}