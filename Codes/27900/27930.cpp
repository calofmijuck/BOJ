#include <bits/stdc++.h>
using namespace std;

vector<char> YONSEI = { 'Y', 'O', 'N', 'S', 'E', 'I' };
vector<char> KOREA = { 'K', 'O', 'R', 'E', 'A' };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    int yonsei = 0, korea = 0;
    for (char c : str) {
        if (c == YONSEI[yonsei]) {
            yonsei++;
        }

        if (c == KOREA[korea]) {
            korea++;
        }

        if (yonsei == 6) {
            cout << "YONSEI";
            break;
        }

        if (korea == 5) {
            cout << "KOREA";
            break;
        }
    }
    return 0;
}
