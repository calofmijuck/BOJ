#include <bits/stdc++.h>
using namespace std;

string blink(string str) {
	string ret(str.size(), ' ');
	int lim = (str.size() - 1) / 2;
	for(int i = 0; i <= lim; ++i)
		ret[2 * i] = str[i]; 
	for(int i = str.size() - 1, j = 1; i > lim; --i, ++j)
		ret[2 * j - 1] = str[i];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x;
	string str;
	cin >> x >> str;
	string tmp(str);
	int cyc = 0;
	while(true) {
		cyc++;
		tmp = blink(tmp);
		if(tmp == str)
			break;
	}
	x = cyc - (x % cyc);
	for(int i = 0; i < x; ++i)
		str = blink(str);
	cout << str;
	return 0;
}