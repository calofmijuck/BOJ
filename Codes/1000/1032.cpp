#include <iostream>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    char arr[str.size()];
    for(int i = 0; i < str.size(); i++) arr[i] = str.at(i);
    arr[str.size()] = '\0';
    for(int i = 1; i < n; i++) {
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            if(arr[j] != str.at(j)) arr[j] = '?';
        }
    }
    printf("%s\n", arr);
}
