#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) putchar('*');
    for(int i = 0; i < 2 * n - 3; ++i) putchar(' ');
    for(int i = 0; i < n; ++i) putchar('*');
    puts("");
    for(int i = 1; i <= n - 2; ++i) {
        for(int j = 0; j < i; ++j) putchar(' ');
        putchar('*');
        for(int j = 0; j < n - 2; ++j) putchar(' ');
        putchar('*');
        for(int j = 0; j < 2 * n - 3 - 2 * i; ++j) putchar(' ');
        putchar('*');
        for(int j = 0; j < n - 2; ++j) putchar(' ');
        putchar('*');
        puts("");
    }
    for(int i = 0; i < n - 1; ++i) putchar(' ');
    putchar('*');
    for(int i = 0; i < n - 2; ++i) putchar(' ');
    putchar('*');
    for(int i = 0; i < n - 2; ++i) putchar(' ');
    putchar('*');
    puts("");
    for(int i = n - 2; i >= 1; --i) {
        for(int j = 0; j < i; ++j) putchar(' ');
        putchar('*');
        for(int j = 0; j < n - 2; ++j) putchar(' ');
        putchar('*');
        for(int j = 0; j < 2 * n - 3 - 2 * i; ++j) putchar(' ');
        putchar('*');
        for(int j = 0; j < n - 2; ++j) putchar(' ');
        putchar('*');
        puts("");
    }
    for(int i = 0; i < n; ++i) putchar('*');
    for(int i = 0; i < 2 * n - 3; ++i) putchar(' ');
    for(int i = 0; i < n; ++i) putchar('*');
    return 0;
}
