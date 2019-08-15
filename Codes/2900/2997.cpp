#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if(2 * arr[1] == arr[0] + arr[2]) {
        cout << arr[2] + (arr[2] - arr[1]);
    } else if(arr[1] - arr[0] == 2 * (arr[2] - arr[1])) {
        cout << (arr[0] + arr[1]) / 2;
    } else {
        cout << (arr[1] + arr[2]) / 2;
    }
}
