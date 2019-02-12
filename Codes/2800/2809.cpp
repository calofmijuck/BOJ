#include <bits/stdc++.h>
using namespace std;
#define MaxN 100

char street[300003];
int arr[300003], n, m;

class Trie {
public:
	Trie* child[26];
	Trie* fail;
	int wLen;
	Trie() {
		for(int i = 0; i < 26; ++i) child[i] = NULL;
		wLen = 0;
	}
	~Trie() {
		for(int i = 0; i < 26; ++i) if(child[i]) delete child[i];
	}
	void insert(char str[], int len) {
		if(*str == '\0') {
			wLen = len;
			return;
		}
		int idx = *str - 'a';
		Trie* next = child[idx];
		if(!next) {
			next = new Trie;
			child[idx] = next;
		}
		next -> insert(str + 1, len);
	}
};

void AC() {
	for(int i = 0; i < m; i += MaxN) {
		Trie* root = new Trie;
		char str[5005];
		for(int j = 0; j < m && j < MaxN; ++j) {
			scanf("%s", str);
			root -> insert(str, strlen(str));
		}
		queue<Trie*> q;
		q.push(root);
		while(!q.empty()) {
			Trie* curr = q.front(); q.pop();
			for(int j = 0; j < 26; ++j) {
				Trie* next = curr -> child[j];
				if(!next) continue;
				if(curr == root) next -> fail = root; // always root for first level nodes
				else { // follow parent's fail and find fail
					Trie* t = curr -> fail;
					while(t != root && t -> child[j] == NULL) t = t -> fail;
					if(t -> child[j]) t = t -> child[j];
					next -> fail = t;
					// print
					if(t -> wLen > 0 && t -> wLen > next -> wLen) next -> wLen = t -> wLen;
				}
				q.push(next);
			}
		}
		// search
		Trie* curr = root;
		for(int j = 0; j < n; ++j) {
			int idx = street[j] - 'a';
			while(curr != root && curr -> child[idx] == NULL) curr = curr -> fail;
			if(curr -> child[idx]) curr = curr -> child[idx];
			if(curr -> wLen > 0 && arr[j] < curr -> wLen) arr[j] = curr -> wLen;
		}
		delete root;
	}
}

int main() {
	scanf("%d %s %d", &n, street, &m);
	AC();
	int ans = 0, rest = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(arr[i] > rest) rest = arr[i];
		if(rest > 0) rest--;
		else ans++;
	}
	printf("%d", ans);
	return 0;
}
