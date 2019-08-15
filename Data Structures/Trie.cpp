#include <bits/stdc++.h>
using namespace std;

struct Trie {
    bool finish;
    Trie* next[26];

    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for(int i = 0; i < 26; ++i) {
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

    // Can be modified
    bool find(const char* key) {
        if(*key == '\0') return 0;
        if(finish) return 1;
        int curr = *key - '0';
        return next[curr] -> find(key + 1);
    }
};
