#include <bits/stdc++.h>
using namespace std;

struct Trie {
    bool finish;
    Trie* next[10];

    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for(int i = 0; i < 10; ++i) {
            if(next[i]) delete next[i];
        }
    }

    void insert(const char* key) {
        if(*key == '\0') finish = true;
        else {
            int curr = *key - '0';
            if(!next[curr]) next[curr] = new Trie();
            next[curr] -> insert(key + 1);
        }
    }

    bool find(const char* key) {
        if(*key == '\0') return 0;
        if(finish) return 1;
        int curr = *key - '0';
        return next[curr] -> find(key + 1);
    }
};

char number[10101][15];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        Trie *root = new Trie();
        bool found = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%s", number[i]);
            root -> insert(number[i]);
        }
        for(int i = 0; i < n; ++i) {
            if(root -> find(number[i])) found = 1;
        }
        printf("%s\n", found ? "NO" : "YES");
    }
}
