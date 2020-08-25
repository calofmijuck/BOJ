#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Board;

// 2 bits: 00 U, 01 R, 10 D, 11 L
vector<int> parse_moves(int move_flag) {
    vector<int> moves;
    for(int i = 0; i < 5; ++i) {
        int v = move_flag & 3;
        move_flag >>= 2;
        moves.push_back(v);
    }
    return moves;
}

int find_max(Board board) {
    int ret = 0, len = board.size();
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < len; ++j)
            ret = max(ret, board[i][j]);
    }
    return ret;
}

stack<int> merge(vector<int> tmp) {
    stack<int> st;
    bool merged = false;
    for(int i = 0; i < tmp.size(); ++i) {
        if(st.empty() || st.top() != tmp[i]) {
            st.push(tmp[i]);
            merged = false;
        } else {
            if(!merged) {
                st.pop();
                st.push(tmp[i] << 1);
                merged = true;
            } else {
                st.push(tmp[i]);
                merged = false;
            }
        }
    }
    return st;
}

void move_up(Board& board) {
    int n = board.size();
    for(int j = 0; j < n; ++j) {
        vector<int> tmp;
        for(int i = 0; i < n; ++i) {
            if(board[i][j] != 0)
                tmp.push_back(board[i][j]);
        }

        stack<int> st = merge(tmp);

        int k = st.size();
        for(int i = n - 1; i >= k; --i)
            board[i][j] = 0;
        for(int i = k - 1; i >= 0; --i) {
            board[i][j] = st.top();
            st.pop();
        }
    }
}

void move_down(Board& board) {
    int n = board.size();
    for(int j = 0; j < n; ++j) {
        vector<int> tmp;
        for(int i = n - 1; i >= 0; --i) {
            if(board[i][j] != 0)
                tmp.push_back(board[i][j]);
        }

        stack<int> st = merge(tmp);

        int k = st.size();
        for(int i = 0; i < n - k; ++i)
            board[i][j] = 0;
        for(int i = n - k; i < n; ++i) {
            board[i][j] = st.top();
            st.pop();
        }
    }
}

void move_left(Board& board) {
    int n = board.size();
    for(int i = 0; i < n; ++i) {
        vector<int> tmp;
        for(int j = 0; j < n; ++j) {
            if(board[i][j] != 0)
                tmp.push_back(board[i][j]);
        }

        stack<int> st = merge(tmp);

        int k = st.size();
        for(int j = n - 1; j >= k; --j)
            board[i][j] = 0;
        for(int j = k - 1; j >= 0; --j) {
            board[i][j] = st.top();
            st.pop();
        }
    }
}

void move_right(Board& board) {
    int n = board.size();
    for(int i = 0; i < n; ++i) {
        vector<int> tmp;
        for(int j = n - 1; j >= 0; --j) {
            if(board[i][j] != 0)
                tmp.push_back(board[i][j]);
        }

        stack<int> st = merge(tmp);

        int k = st.size();
        for(int j = 0; j < n - k; ++j)
            board[i][j] = 0;
        for(int j = n - k; j < n; ++j) {
            board[i][j] = st.top();
            st.pop();
        }
    }
}


int main() {
    int n; scanf("%d", &n);
    Board board(n);
    for(int i = 0; i < n; ++i) {
        board[i].resize(n);
        for(int j = 0; j < n; ++j)
            scanf("%d", &board[i][j]);
    }
    int move_flag = 0, mx = 0;
    for(; move_flag < 1024; ++move_flag) {
        vector<int> moves = parse_moves(move_flag);
        Board tmp(board);
        for(int m : moves) {
            if(m == 0)
                move_up(tmp);
            else if(m == 1)
                move_right(tmp);
            else if(m == 2)
                move_down(tmp);
            else if(m == 3)
                move_left(tmp);
        }
        mx = max(mx, find_max(tmp));
    }
    printf("%d", mx);
    return 0;
}