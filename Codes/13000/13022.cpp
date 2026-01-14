#include <bits/stdc++.h>
using namespace std;

enum state {
    INVALID,
    SEEN_W,
    SEEN_O,
    SEEN_L,
    SEEN_F
};

bool solve(string& str) {
    int w_count = 0;
    int curr = 0;

    state s = INVALID;
    for (char c : str) {
        switch (s) {
            case INVALID:
                if (c != 'w') {
                    return false;
                } else {
                    w_count = 1;
                    s = SEEN_W;
                }
                break;
            case SEEN_W:
                if (c == 'w') {
                    w_count++;
                } else if (c == 'o') {
                    curr = w_count - 1;
                    s = SEEN_O;
                } else {
                    return false;
                }
                break;
            case SEEN_O:
                if (c == 'o') {
                    curr--;
                } else if (c == 'l') {
                    if (curr != 0) {
                        return false;
                    }

                    curr = w_count - 1;
                    s = SEEN_L;
                } else {
                    return false;
                }
                break;
            case SEEN_L:
                if (c == 'l') {
                    curr--;
                } else if (c == 'f') {
                    if (curr != 0) {
                        return false;
                    }

                    curr = w_count - 1;
                    s = SEEN_F;
                } else {
                    return false;
                }
                break;
            case SEEN_F:
                if (c == 'f') {
                    curr--;
                } else if (c == 'w') {
                    if (curr != 0) {
                        return false;
                    }

                    w_count = 1;
                    s = SEEN_W;
                } else {
                    return false;
                }
                break;
            default:
                // should not happen
                break;
        }
    }
    if (curr != 0 || s != SEEN_F) {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
