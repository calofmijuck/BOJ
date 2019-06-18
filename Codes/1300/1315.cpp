#include <bits/stdc++.h>
using namespace std;

int n, str[101], inte[101], p[101], dp[1010][1010];
bool visited[101];

int solve(int s, int i) {
	int &ret = dp[s][i];
	if(ret != -1) return ret;
	ret = 0;
	int pnt = 0;
	vector<int> vec;
    for(int j = 0; j < n; ++j) {
        if(str[j] <= s || inte[j] <= i) {
            ret++;
            if(!visited[j]) {
                visited[j] = true;
                pnt += p[j];
                vec.push_back(j);
            }
        }
    }
    for(int p = 0; p <= pnt; ++p) {
        ret = max(solve(min(s + p, 1000), min(i + pnt - p, 1000)), ret);
    }
    for(int quest : vec) visited[quest] = false;
	return ret;
}

int main() {
    scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d %d", str + i, inte + i, p + i);
	memset(dp, -1, sizeof(dp));
	printf("%d", solve(1, 1));
    return 0;
}
