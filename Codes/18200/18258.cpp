#include <iostream>
using namespace std;

#define MAX_LEN 2000000

int queue[MAX_LEN + 20];
int f = 0, b = 0;

void push(int x) {
	queue[b] = x;
	b = (b + 1) % MAX_LEN;
}

int pop() {
	if(b == f) return -1;
	int ret = queue[f];
	f = (f + 1) % MAX_LEN;
	return ret;
}

int size() {
	int s = b - f;
	if(s < 0) s += 2000000;
	return s;
}

int empty() {
	return b == f;
}

int front() {
	if(b == f) return -1;
	return queue[f];
}

int back() {
	if(b == f) return -1;
	if(b - 1 < 0) return queue[MAX_LEN - 1];
	return queue[b - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while(n--) {
		string str;
		int x;
		cin >> str;
		if(str[0] == 'p') {
			if(str.size() == 4) {
				cin >> x;
				push(x);
			} else
				cout << pop() << '\n';
		} else if(str[0] == 's')
			cout << size() << '\n';
		else if(str[0] == 'e')
			cout << empty() << '\n';
		else if(str[0] == 'f')
			cout << front() << '\n';
		else if(str[0] == 'b')
			cout << back() << '\n';
	}
	return 0;
}