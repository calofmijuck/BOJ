#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

map<string, pii> direction;

pii toPair(string s) {
    return {s[1] - '0', s[0] - 'A' + 1};
}

string toPosition(pii p) {
    string s = "";
    s.push_back(p.second - 1 + 'A');
    s.push_back(p.first + '0');
    return s;
}

bool checkRange(pii p) {
    return 0 < p.first && p.first <= 8 && 0 < p.second && p.second <= 8;
}

void init() {
    direction["R"] = {0, 1};
    direction["L"] = {0, -1};
    direction["B"] = {-1, 0};
    direction["T"] = {1, 0};
    direction["RT"] = {1, 1};
    direction["LT"] = {1, -1};
    direction["RB"] = {-1, 1};
    direction["LB"] = {-1, -1};
}

void move(pii& king, pii& rock, pii p) {
    pii newKing = {king.first + p.first, king.second + p.second};
    if(!checkRange(newKing)) return;    
    if(newKing == rock) {
        pii newRock = {rock.first + p.first, rock.second + p.second};
        if(!checkRange(newRock)) return;
        king = newKing;
        rock = newRock;
    }
    king = newKing;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    string s, t, x;
    int n;
    cin >> s >> t >> n;
    pii king = toPair(s), rock = toPair(t);
    for(int i = 0; i < n; ++i) {
        cin >> x;
        move(king, rock, direction[x]);
    }
    s = toPosition(king);
    t = toPosition(rock);
    cout << s << '\n' << t;
    return 0;
}