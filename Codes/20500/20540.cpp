#include <bits/stdc++.h>
using namespace std;

string revert_mbti(string& mbti) {
    string result;
    result.push_back((mbti[0] == 'I') ? 'E' : 'I');
    result.push_back((mbti[1] == 'N') ? 'S' : 'N');
    result.push_back((mbti[2] == 'F') ? 'T' : 'F');
    result.push_back((mbti[3] == 'P') ? 'J' : 'P');
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string mbti;
    cin >> mbti;

    cout << revert_mbti(mbti);
    return 0;
}
