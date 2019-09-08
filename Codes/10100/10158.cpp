#include <iostream>
using namespace std;

int main() {
    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;
    int rx = t % (2 * w), ry = t % (2 * h);
    p += rx, q += ry;
    if(p >= w) {
        p -= w;
        p = w - p;
        if(p < 0) p = -p;
    }
    if(q >= h) {
        q -= h;
        q = h - q;
        if(q < 0) q = -q;
    }
    cout << p << ' ' << q;
}