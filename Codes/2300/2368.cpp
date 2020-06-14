#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, cnt, ans;
int gnd[110][110];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

inline bool check(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void fill() {
	bool visited[110][110] = {false};
	visited[0][0] = true;
	gnd[0][0] = -1;
	queue<pii> q;
	q.push({0, 0});
	while(!q.empty()) {
		pii c = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = c.first + dx[i];
			int ny = c.second + dy[i];
			if(!check(nx, ny) || visited[nx][ny]) continue;
			if(gnd[nx][ny] == 1) continue;
			gnd[nx][ny] = -1;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> gnd[i][j];
			if(gnd[i][j] == 1) cnt++;
		}
	}
	while(cnt > 0) {
		fill();
		vector<pii> melt;
		for(int i = 1; i < n - 1; ++i) {
			for(int j = 1; j < m - 1; ++j) {
				if(gnd[i][j] == 1) {
					int side = 0;
					for(int k = 0; k < 4; ++k) {
						int nx = i + dx[k], ny = j + dy[k];
						side += (gnd[nx][ny] == -1);
					}
					if(side >= 2)
						melt.push_back({i, j});
				}
			}
		}
		for(pii p : melt) 
			gnd[p.first][p.second] = 0;
		ans++;
		cnt -= melt.size();
	}
	cout << ans;
	return 0;
}