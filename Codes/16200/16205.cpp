#include <bits/stdc++.h>
using namespace std;
char camel[110], snake[210], pascal[110];

char toUpper(char c) {
    return c - 32;
}

char toLower(char c) {
    return c + 32;
}

int main() {
    int n; string str;
    cin >> n >> str;
    int offset = 0, i = 0;
    if(n == 1) {
        char c = str.at(i);
        camel[i] = c;
        snake[i] = c;
        pascal[i] = toUpper(c);
        for(i = 1; i < str.size(); i++) {
            c = str.at(i);
            camel[i] = c;
            pascal[i] = c;
            if('A' <= c && c <= 'Z') {
                snake[i + offset] = '_';
                offset++;
                snake[i + offset] = toLower(c);
            } else {
                snake[i + offset] = c;
            }
        }
    } else if(n == 2) {
        char c = str.at(i);
        camel[i] = c;
        snake[i] = c;
        pascal[i] = toUpper(c);
        bool underbar = false;
        for(i = 1; i < str.size(); i++) {
            c = str.at(i);
            snake[i] = str.at(i);
            if(c == '_') {
                offset++;
                underbar = true;
                continue;
            }
            if(underbar) {
                camel[i - offset] = toUpper(c);
                pascal[i - offset] = toUpper(c);
            } else {
                camel[i - offset] = c;
                pascal[i - offset] = c;
            }
            underbar = false;
        }
    } else {
        char c = str.at(i);
        camel[i] = toLower(c);
        snake[i] = toLower(c);
        pascal[i] = c;
        for(i = 1; i < str.size(); i++) {
            c = str.at(i);
            pascal[i] = c;
            camel[i] = c;
            if('A' <= c && c <= 'Z') {
                snake[i + offset] = '_';
                offset++;
                snake[i + offset] = toLower(c);
            } else {
                snake[i + offset] = c;
            }
        }
    }
    camel[i] = '\0';
    snake[i + offset] = '\0';
    pascal[i] = '\0';
    printf("%s\n%s\n%s", camel, snake, pascal);
    return 0;
}
