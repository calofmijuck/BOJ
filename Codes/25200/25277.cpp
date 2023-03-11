#include <bits/stdc++.h>
using namespace std;

set<string> keywords = { "he", "she", "him", "her" };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int words;
    cin >> words;

    int count = 0;
    for (int i = 0; i < words; ++i) {
        string word;
        cin >> word;

        if (keywords.find(word) != end(keywords)) {
            count++;
        }
    }
    cout << count;
    return 0;
}
