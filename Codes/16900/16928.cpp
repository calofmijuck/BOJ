#include <bits/stdc++.h>
using namespace std;

#define START 1
#define END 100

typedef struct {
    int position;
    int moves;
} game_state;

map<int, int> event;
bool visited[101];

int bfs() {
    queue<game_state> q;
    game_state initial = {START, 0};
    
    q.push(initial);
    visited[initial.position] = true;
    while (!q.empty()) {
        game_state curr = q.front();
        q.pop();

        for (int step = 1; step <= 6; ++step) {
            int next_position = curr.position + step;
            int moves = curr.moves + 1;

            if (next_position == END) {
                return moves;
            }

            if (visited[next_position]) {
                continue;
            }

            visited[next_position] = true;
            if (event.find(next_position) != event.end()) {
                next_position = event[next_position];
                visited[next_position] = true;
            }
            game_state next = {next_position, moves};
            q.push(next);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        int start, end;
        cin >> start >> end;
        event.insert({start, end});
    }

    cout << bfs();
    return 0;
}
