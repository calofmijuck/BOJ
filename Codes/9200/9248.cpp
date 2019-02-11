#include<bits/stdc++.h>
using namespace std;

class SuffixArray {
public:
    int n;
    string s;
    vector<int> rank, temprank, sa, tempsa, c, lcp;
    SuffixArray(string _s) {
        n = _s.size(); s = _s;
        rank.resize(n); temprank.resize(n); sa.resize(n); tempsa.resize(n); lcp.resize(n);
        constructSA();
        constructLCP();
    }

    void countingSort(int k) {
        int sum = 0, maxi = max(270, n);
        c.clear(); c.resize(maxi+10);
        for(auto& e : c ) e = 0;
        for(int i = 0; i < n; i++) c[i + k < n ? rank[i + k] : 0]++;
        for(int i = 0; i < maxi; i++){
            int t = c[i]; c[i] = sum; sum += t;
        }
        for(int i = 0; i < n; i++) tempsa[c[sa[i] + k < n ? rank[sa[i] + k] : 0]++] = sa[i];
        for(int i = 0; i < n; i++) sa[i] = tempsa[i];
    }

    void constructSA() {
        for(int i = 0; i < n; i++) rank[i] = s[i];
        for(int i = 0; i < n; i++) sa[i] = i;
        for(int k = 1; k < n; k <<= 1){
            countingSort(k); countingSort(0);
            int r = 0;
            temprank[sa[0]] = 0;
            for(int i = 1; i < n; i++){
                temprank[sa[i]] = (rank[sa[i]] == rank[sa[i - 1]] && rank[sa[i] + k] == rank[sa[i - 1] + k]) ? r : ++r;
            }
            for(int i = 0; i < n; i++) rank[i] = temprank[i];
            if(rank[sa[n - 1]] == n - 1) break;
        }
    }

    void constructLCP() {
        int h = 0;
        for(int i = 0; i < n; i++){
            if(rank[i]){
                int j = sa[rank[i] - 1];
                while(s[i + h] == s[j + h]) h++;
                lcp[rank[i]] = h;
            }
            if(h > 0) h--;
        }
    }
};

int main() {
    string s;
    cin >> s;
    s.push_back('$');
    SuffixArray SA = SuffixArray(s);
    vector<int> arr = SA.sa, res = SA.lcp;
    for(int i = 1; i < arr.size(); ++i) printf("%d ", arr[i] + 1);
    printf("\nx ");
    for(int i = 2; i < res.size(); ++i) printf("%d ", res[i]);
}
