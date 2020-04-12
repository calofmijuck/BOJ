#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int sx, sy, n, t, ate, sz = 2;
int board[22][22], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
bool visited[22][22];

inline bool check(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool bfs(int x, int y) {
	visited[x][y] = true;
	vector<pair<int, pii>> edible; 
	queue<pair<pii, int>> q;
	q.push({{x, y}, t});
	while(!q.empty()) {
		pair<pii, int> curr = q.front(); q.pop();
		pii loc = curr.first;
		for(int i = 0; i < 4; ++i) {
			int nx = loc.first + dx[i], ny = loc.second + dy[i];
			if(!check(nx, ny) || visited[nx][ny] || sz < board[nx][ny]) continue;
			visited[nx][ny] = true;
			if(board[nx][ny] != 0 && sz > board[nx][ny])
				edible.push_back({curr.second + 1, {nx, ny}});				
			q.push({{nx, ny}, curr.second + 1});
		}
	}
	if(edible.empty())
		return false;
	sort(edible.begin(), edible.end());
	pii eat = edible[0].second;
	sx = eat.first,	sy = eat.second;
	t = edible[0].first;
	board[sx][sy] = 0;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if(board[i][j] == 9) {
				sx = i;
				sy = j;
				board[i][j] = 0;
			}
		}
	}
	while(bfs(sx, sy)) {
		ate++;
		if(ate == sz) {
			sz++;
			ate = 0;
		}
		memset(visited, false, sizeof(visited));
	}
	cout << t;
	return 0;
}
