#include <bits/stdc++.h>
using namespace std;

#define LENGTH 10000

class Queue {
private:
    int data[LENGTH];
    int idxf, idxb; // front, back index
public:
    Queue() : idxf(-1), idxb(-1) {}

    void push(int num) {
        ++idxb;
        data[idxb] = num;
    }

    int pop() {
        if(idxb == idxf) return -1;
        ++idxf;
        int ret = data[idxf];
        return ret;
    }

    int size() {
        return idxb - idxf;
    }

    int empty() {
        if(idxb - idxf > 0) return 0;
        return 1;
    }

    int front() {
        if(idxb == idxf) return -1;
        else return data[idxf + 1];
    }

    int back() {
        if(idxb == idxf) return -1;
        else return data[idxb];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    string str;
    Queue q;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        switch(str.at(0)) {
            case 'p':
                if(str.at(1) == 'u') {
                    cin >> input;
                    q.push(input);
                }
                else cout << q.pop() << '\n';
                break;
            case 's':
                cout << q.size() << '\n';
                break;
            case 'e':
                cout << q.empty() << '\n';
                break;
            case 'f':
                cout << q.front() << '\n';
                break;
            case 'b':
                cout << q.back() << '\n';
                break;
            default:;
        }
    }
    return 0;
}
