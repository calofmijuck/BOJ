#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int board[9][9];
vector<pii> empty;
bool found = false;

bool check(int x, int y);

void solve(int idx) {
	if(idx == empty.size()) {
		found = true;
		return;
	}
	pii p = empty[idx];
	for(int i = 1; i <= 9; ++i) {
		board[p.first][p.second] = i;
		if(check(p.first, p.second))
			solve(idx + 1);
		if(found)
			return;
	}
	board[p.first][p.second] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	for(int i = 0; i < 9; ++i) {
		cin >> str;
		for(int j = 0; j < str.size(); ++j) {
			board[i][j] = str[j] - '0';
			if(board[i][j] == 0)
				empty.push_back({i, j});
		}
	}
	solve(0);
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j)
			cout << board[i][j];
		cout << '\n';
	}
	return 0;
}

bool check(int x, int y) {
	int chk = 0;
	for(int i = 0; i < 9; ++i) {
		if(board[x][i] == 0) continue;
		int k = 1 << board[x][i];
		if(chk & k)
			return false;
		chk |= k;
	}
	chk = 0;
	for(int i = 0; i < 9; ++i) {
		if(board[i][y] == 0) continue;
		int k = 1 << board[i][y];
		if(chk & k)
			return false;
		chk |= k;
	}
	int nx = x / 3 * 3, ny = y / 3 * 3;
	chk = 0;
	for(int i = nx; i < nx + 3; ++i) {
		for(int j = ny; j < ny + 3; ++j) {
			if(board[i][j] == 0) continue;
			int k = 1 << board[i][j];
			if(chk & k)
				return false;
			chk |= k;
		}
	}
	return true;
}