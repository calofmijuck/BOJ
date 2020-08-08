#include <bits/stdc++.h>
using namespace std;

string board[100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> board[i];
	if(n == 1) {
		cout << 0;
		return 0;
	}
	
	// 4 corners
	board[1][1] = (board[0][0] == '0') ? 0 : '*';
	board[n - 2][n - 2] = (board[n - 1][n - 1] == '0') ? 0 : '*';
	board[1][n - 2] = (board[0][n - 1] == '0') ? 0 : '*';
	board[n - 2][1] = (board[n - 1][0] == '0') ? 0 : '*';
	
	// top line
	for(int j = 1; j < n - 2; ++j) {
		char c = board[0][j];
		if(c == '0')
			board[1][j + 1] = 0;
		else if(c == '3') {
			board[1][j + 1] = '*';
		} else {
			int cnt = (board[1][j - 1] == '*') + (board[1][j] == '*');
			if(c == '1') {
				board[1][j + 1] = (cnt == 1) ? 0 : '*';
			} else if(c == '2') {
				board[1][j + 1] = (cnt == 1) ? '*' : 0;
			}
		}
	}

	// left line
	for(int i = 1; i < n - 2; ++i) {
		char c = board[i][0];
		if(c == '0')
			board[i + 1][1] = 0;
		else if(c == '3') {
			board[i + 1][1] = '*';
		} else {
			int cnt = (board[i - 1][1] == '*') + (board[i][1] == '*');
			if(c == '1') {
				board[i + 1][1] = (cnt == 1) ? 0 : '*';
			} else if(c == '2') {
				board[i + 1][1] = (cnt == 1) ? '*' : 0;
			}
		}
	}

	// right line
	for(int i = 1; i < n - 2; ++i) {
		char c = board[i][n - 1];
		if(c == '0')
			board[i + 1][n - 2] = 0;
		else if(c == '3') {
			board[i + 1][n - 2] = '*';
		} else {
			int cnt = (board[i - 1][n - 2] == '*') + (board[i][n - 2] == '*');
			if(c == '1') {
				board[i + 1][n - 2] = (cnt == 1) ? 0 : '*';
			} else if(c == '2') {
				board[i + 1][n - 2] = (cnt == 1) ? '*' : 0;
			}
		}
	}

	// bottom line
	for(int j = 1; j < n - 2; ++j) {
		char c = board[n - 1][j];
		if(c == '0')
			board[n - 2][j + 1] = 0;
		else if(c == '3') {
			board[n - 2][j + 1] = '*';
		} else {
			int cnt = (board[n - 2][j - 1] == '*') + (board[n - 2][j] == '*');
			if(c == '1') {
				board[n - 2][j + 1] = (cnt == 1) ? 0 : '*';
			} else if(c == '2') {
				board[n - 2][j + 1] = (cnt == 1) ? '*' : 0;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < n - 1; ++i) {
		for(int j = 1; j < n - 1; ++j) {
			if(board[i][j] != 0)
				ans++;
		}
	}
	cout << ans;
	return 0;
}