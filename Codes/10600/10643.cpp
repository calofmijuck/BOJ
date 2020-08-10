#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[8];
	for(int i = 0; i < 8; ++i)
		scanf("%d", &arr[i]);
	int mx = 0;
	for(int i = 0; i < 8; ++i)
		mx = max(mx, arr[i] + arr[(i + 1) % 8] + arr[(i + 2) % 8] + arr[(i + 3) % 8]);
	printf("%d", mx);
	return 0;
}