#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int k, n;
		string op;
		cin >> k;
		multiset<int> ms;
		for(int i = 0; i < k; ++i) {
			cin >> op >> n;
			if(op[0] == 'I') {
				ms.insert(n);
			} else {
				if(ms.empty()) continue;
				if(n == -1)	ms.erase(ms.begin());
				else ms.erase(--ms.end());
			}
		}
		if(ms.empty()) cout << "EMPTY\n";
		else {
			cout << *--ms.end() << " " << *ms.begin() << '\n';
		}
	}
	return 0;
}
