// Integer Stack implemented with array
#define LENGTH 10000

class Stack {
private:
    int data[LENGTH];
    int idx;
public:
    Stack() : idx(-1) {}

    void push(int num) {
        ++idx;
        data[idx] = num;
    }

    void pop() {
        --idx;
    }

    int top() {
        if(idx == -1) return -1;
        return data[idx];
    }

    int size() {
        return idx + 1;
    }

    int empty() {
        if(idx == -1) return 1;
        else return 0;
    }
};
