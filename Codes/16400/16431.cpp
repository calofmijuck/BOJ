#include <bits/stdc++.h>
using namespace std;

int main() {
    int br, bc, dr, dc, jr, jc, daisy, bessie;
    scanf("%d %d %d %d %d %d", &br, &bc, &dr, &dc, &jr, &jc);
    daisy = abs(jr - dr) + abs(jc - dc);
    bessie = abs(jr - br) + abs(jc - bc) - min(abs(jr - br), abs(jc - bc));
    if(daisy > bessie) printf("bessie");
    else if(daisy < bessie) printf("daisy");
    else printf("tie");
    return 0;
}
