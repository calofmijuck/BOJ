#include <stdio.h>

#define MAX 524288

int cnt, rc;
char buf[MAX];

inline char gChar(void) {
    if(cnt % MAX == 0) {
        cnt = 0;
        rc = fread(buf, 1, MAX, stdin);
    }
    return cnt < rc ? buf[cnt++] : 0;
}

inline int _readInt(int *ptr) {
    int n = 0, c = 0;
    *ptr = 0;
    while(1) {
        char read = gChar();
        if(read >= '0' && read <= '9') {
            read -= '0';
            n *= 10;
            n += read;
        } else {
            *ptr = n;
            return n == 0 ? 0 : !c;
        }
        c++;
    }
    *ptr = n;
    return 0;
}

inline int readInt(void) {
    int ptr;
    while(_readInt(&ptr));
    return ptr;
}

int main() {
    int n, t, r;
    long long sum = 0;
    t = readInt();
    n = t;
    while(t--) {
        r = readInt();
        sum += r;
    }
    printf("%d\n%lld", n, sum);
}
