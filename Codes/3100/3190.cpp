#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, string> Move;

int board[101][101], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dirIdx = 0;
vector<pii> snake;
vector<Move> moves;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    int l;
    cin >> l;
    for(int i = 0; i < l; ++i) {
        int t;
        string s;
        cin >> t >> s;
        moves.push_back({t, s});
    }
    snake.push_back({1, 1});
    board[1][1] = -1;
    int t = 0, moveIdx = 0;
    while(true) {
        t++;
        pii prev, next = {snake[0].first + dx[dirIdx], snake[0].second + dy[dirIdx]};
        if(next.first <= 0 || next.first > n || next.second <= 0 || next.second > n)
            break;
        int k = board[next.first][next.second];
        if(k == -1) break;        
        for(int i = 0; i < snake.size(); ++i) {
            prev = snake[i];
            board[prev.first][prev.second] = 0;
            snake[i] = next;
            board[next.first][next.second] = -1;
            next = prev;
        }
        if(k == 1) snake.push_back(next);

        if(moveIdx < moves.size() && moves[moveIdx].first == t) {
            if(moves[moveIdx].second[0] == 'L')
                dirIdx = (dirIdx + 3) % 4;
            else
                dirIdx = (dirIdx + 1) % 4;
            moveIdx++;
        }
    }
    cout << t;
    return 0;
}