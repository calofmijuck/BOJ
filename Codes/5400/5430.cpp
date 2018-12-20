#include <bits/stdc++.h>
using namespace std;

int arr[101010];
char str[101010], op[505050];

int main() {
    int t, n, st, ed;
    scanf("%d", &t);
    while(t--) {
        scanf("%s %d %s", str, &n, op);
        deque<int> dq;
        int idx = 0;
        while(op[idx]) {
            if(isdigit(op[idx])) {
                int x = 0;
                while(op[idx] && isdigit(op[idx])) {
                    x *= 10;
                    x += op[idx] - '0';
                    ++idx;
                }
                dq.push_back(x);
            } else ++idx;
        }
        int front = 1;
        bool valid = true;
        for(int i = 0; str[i]; ++i) {
            if(str[i] == 'R') front ^= 1;
            else {
                if(!dq.empty() && !front) {
                    dq.pop_back();
                } else if(!dq.empty() && front) {
                    dq.pop_front();
                } else {
                    valid = false;
                    break;
                }
            }
        }
        if(valid) {
            printf("[");
            while(!dq.empty()) {
                if(front) {
                    printf("%d", dq.front());
                    dq.pop_front();
                } else {
                    printf("%d", dq.back());
                    dq.pop_back();
                }
                if(!dq.empty()) printf(",");
            }
            printf("]\n");
        } else printf("error\n");
    }
    return 0;
}
