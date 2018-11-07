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
