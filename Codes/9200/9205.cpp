#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

inline int dist(pii x, pii y) {
	return abs(x.first - y.first) + abs(x.second - y.second); 
}

void bfs(pii st, pii ed, vector<pii>& store) {
	int bottle = 20;
	map<pii, bool> visited;
	visited[st] = true;
	queue<pii> q;
	q.push(st);
	while(!q.empty()) {
		pii curr = q.front();
		q.pop();
		if(dist(curr, ed) <= 1000) {
			cout << "happy\n";
			return;
		}
		for(pii next : store) {
			if(!visited[next] && dist(curr, next) <= 1000) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	cout << "sad\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, x, y;
		pii st, ed;
		cin >> n >> st.first >> st.second;
		vector<pii> store;
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			store.push_back({x, y});
		}
		cin >> ed.first >> ed.second;
		bfs(st, ed, store);
	}
	return 0;
}
