#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cube = {
    { 0, 1, 2 }, { 0, 2, 4 }, { 0, 4, 3 }, { 0, 3, 1 },
    { 5, 2, 1 }, { 5, 1, 3 }, { 5, 3, 4 }, { 5, 4, 2 },
};

enum class color {
    BLUE, GREEN, ORANGE, RED, WHITE, YELLOW
};

map<char, color> char_to_color = {
    { 'B', color::BLUE }, { 'G', color::GREEN }, { 'O', color::ORANGE },
    { 'R', color::RED }, { 'W', color::WHITE }, { 'Y', color::YELLOW }
};

vector<vector<color>> pieces(8);

void read_pieces() {
    string line;
    for (int i = 0; i < 8; ++i) {
        getline(cin, line);
        pieces[i] = vector<color>();
        for (int j = 0; j < (int) line.size(); j += 2) {
            pieces[i].push_back(char_to_color[line[j]]);
        }
    }
}

int find_piece(vector<color>& piece, vector<int>& permutation) {
    for (int idx = 0; idx < (int) cube.size(); ++idx) {
        vector<int>& cube_piece = cube[idx];
        bool equal_piece = false;
        for (int rotation = 0; rotation < 3; ++rotation) {
            bool match = true;
            for (int side = 0; side < 3; ++side) {
                match &= (permutation[int(piece[side])] == cube_piece[(side + rotation) % 3]);
            }
            equal_piece |= match;
        }

        if (equal_piece) {
            return idx;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    read_pieces();

    vector<int> permutation = { 0, 1, 2, 3, 4, 5 };
    do {
        bitset<8> used;
        for (vector<color>& piece : pieces) {
            int piece_number = find_piece(piece, permutation);
            if (piece_number == -1 or used[piece_number]) {
                continue;
            }

            used[piece_number] = true;
        }

        if (used.all()) {
            cout << "YES";
            return 0;
        }
    } while (next_permutation(begin(permutation), end(permutation)));

    cout << "NO";
    return 0;
}
