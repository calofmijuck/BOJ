#include <bits/stdc++.h>
using namespace std;

bool isSelf[10100];

int self(int n) {
	int ret = n;
	while(n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	for(int i = 1; i <= 10000; ++i) {
		int k = self(i);
		if(k > 10000) continue;
		isSelf[k] = true;
	}
	for(int i = 1; i <= 10000; ++i) {
		if(!isSelf[i])
			printf("%d\n", i);
	}
	return 0;
}