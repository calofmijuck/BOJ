#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> pos, neg;

int main() {
    int n;
    bool z = false;
    ll score = 0, input;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &input);
        if(input == 0) z = true;
        else if(input == 1) ++score;
        else if(input < 0) neg.push_back(input);
        else pos.push_back(input);
    }
    sort(pos.begin(), pos.end(), greater<ll>());
    sort(neg.begin(), neg.end());
    for(int i = 0; i < (int) pos.size() - 1; i += 2) {
        score += pos[i] * pos[i + 1];
    }
    if(pos.size() & 1) score += pos.back();
    for(int i = 0; i < (int) neg.size() - 1; i += 2) {
        score += neg[i] * neg[i + 1];
    }
    if((neg.size() & 1) && !z) score += neg.back();
    printf("%lld", score);
    return 0;
}
