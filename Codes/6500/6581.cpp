#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	int cnt = 0;
	while(cin >> str) {
		if(str == "<br>") {
			cout << '\n';
			cnt = 0;
		} else if(str == "<hr>") {
			if(cnt != 0)
				cout << '\n';
			for(int i = 0; i < 80; ++i)
				cout << '-';
			cout << '\n';
			cnt = 0;
		} else {
			if(cnt + str.size() + 1 <= 80) {
				if(cnt != 0)
					cout << ' ';
				cout << str;
				cnt += str.size() + 1;
			} else {
				cnt = str.size();
				cout << '\n' << str;
			}
		}
	}
	return 0;
}