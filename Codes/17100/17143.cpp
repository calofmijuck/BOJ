#include <bits/stdc++.h>
using namespace std;

class Shark {
public:
    int x, y, s, d, z;
    bool caught;
    Shark(int x, int y, int s, int d, int z) 
        : x(x), y(y), s(s), d(d), z(z) {
        caught = false;
    }
};

vector<Shark> sharks;
int board[101][101];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
int r, c, m, ans = 0;

void clear_board();
void catch_shark(int);
void move();
void move_shark(Shark&);
inline bool shark_is_at(int, int);
void handle_duplicate_shark(Shark&, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c >> m;
    clear_board();
    for(int i = 0; i < m; ++i) {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        sharks.emplace_back(x, y, s, d, z);
        board[x][y] = i;
    }

    for(int king = 1; king <= c; ++king) {
        catch_shark(king);
        move();
    }
    cout << ans;
    return 0;
}

void clear_board() {
    memset(board, -1, sizeof(board));
}

void catch_shark(int col) {
    int idx = 1;
    while(idx <= r && board[idx][col] < 0)
        ++idx;
    if(idx <= r) {
        int shark_idx = board[idx][col];
        sharks[shark_idx].caught = true;
        ans += sharks[shark_idx].z;
    }
    clear_board();
}

void move() {
    for(int idx = 0; idx < m; ++idx) {
        Shark& shark = sharks[idx];
        if(shark.caught) continue;
        move_shark(shark);
        int x = shark.x, y = shark.y;
        if(shark_is_at(x, y))
            handle_duplicate_shark(shark, idx);
        else
            board[x][y] = idx;
    }
}

int change_direction(int d) {
    if(d == 1)
        return 2;
    else
        return 1;
} 

void move_shark(Shark& shark) {
    int dir = shark.d;
    int move_x = shark.s % (2 * (r - 1));
    int move_y = shark.s % (2 * (c - 1));
    if(dir == 1) {
        int d = shark.x - 1;
        if(d < move_x) {
            int t = move_x - d;
            if(t >= r) {
                shark.x = r - (t - r + 1);
            } else {
                shark.d = 2;
                shark.x = 1 + move_x - d;
            }
        } else {
            shark.x -= move_x;
        }
    } else if(dir == 2) {
        int d = r - shark.x;
        if(d < move_x) {
            int t = move_x - d;
            if(t >= r) {
                shark.x = 1 + (t - r + 1);
            } else {
                shark.d = 1;
                shark.x = r - (move_x - d);
            }
        } else {
            shark.x += move_x;
        }
    } else if(dir == 3) {
        int d = c - shark.y;
        if(d < move_y) {
            int t = move_y - d;
            if(t >= c) {
                shark.y = 1 + (t - c + 1);
            } else {
                shark.d = 4;
                shark.y = c - (move_y - d);
            }
        } else {
            shark.y += move_y;
        }
    } else {
        int d = shark.y - 1;
        if(d < move_y) {
            int t = move_y - d;
            if(t >= c) {
                shark.y = c - (t - c + 1);
            } else {
                shark.d = 3;
                shark.y = 1 + (move_y - d);
            }
        } else {
            shark.y -= move_y;
        }
    }
}

inline bool shark_is_at(int x, int y) {
    return board[x][y] != -1;
}

void handle_duplicate_shark(Shark& shark, int idx) {
    int x = shark.x, y = shark.y;
    Shark& target = sharks[board[x][y]];
    int curr_size = shark.z, cmp_size = target.z;
    if(curr_size > cmp_size) {
        board[x][y] = idx;
        target.caught = true;
    } else
        shark.caught = true;
}
