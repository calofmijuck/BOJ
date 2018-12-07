#include <cstdio>
using namespace std;

int main() {
	int t, p;
	scanf("%d %d", &t, &p);
	if(p < 20) printf("%.6lf", (double) p * t / (60 - p));
	else printf("%.6lf", (double) (p * t + 20 * t) / (100 - p));
	return 0;
}
