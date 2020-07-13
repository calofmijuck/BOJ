#include <bits/stdc++.h>
using namespace std;

int arr[100010];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) 
		scanf("%d", arr + i);
	int mi = abs(arr[0] + arr[n - 1]), ai = 0, aj = n - 1;
	int i = 0, j = n - 1;
	while(true) {
		int l = arr[i] + arr[j];
		if(abs(l) < mi) {
			mi = abs(l), ai = i, aj = j;
		}
		if(l < 0) {
			i++;
		} else {
			j--;
		}
		if(i >= j) break;
	}
	printf("%d %d", arr[ai], arr[aj]);
	return 0;
}
