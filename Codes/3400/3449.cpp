#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string u, v;
        cin >> u >> v;
        int ans = 0;
        for(int i = 0; i < u.size(); ++i) {
            if(v[i] != u[i]) ans++;
        }
        cout << "Hamming distance is " << ans << ".\n";
    }
}
