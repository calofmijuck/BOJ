#include <bits/stdc++.h>
using namespace std;

string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int main() {
    int n;
    string s;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        printf("Case %d: ", i + 1);
        for(int j = 0; j < 5; ++j) {
            cin >> s;
            int idx = -1;
            for(int k = 0; k < 26; ++k) {
                if(morse[k].compare(s) == 0) {
                    idx = k;
                    break;
                }
            }
            printf("%c", (char) 'A' + idx);
        }
        puts("");
    }
    return 0;
}
