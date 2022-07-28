#include <bits/stdc++.h>
using namespace std;

class node {
public:
    char c;
    node* prev;
    node* next;

    node(const char c) : c(c), prev(0), next(0) { };
};

node* insert(node*, char);

node* remove(node*);

node* go_left(node*);

node* go_right(node*);

pair<node*, node*> initialize_string(string& s);

void print_string(node*);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    auto [head, cursor] = initialize_string(s);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string op, c;
        cin >> op;
        switch (op[0]) {
            case 'L':
                cursor = go_left(cursor);
                break;
            case 'D':
                cursor = go_right(cursor);
                break;
            case 'B':
                cursor = remove(cursor);
                break;
            case 'P':
                cin >> c;
                cursor = insert(cursor, c[0]);
                break;
            default:
                break;
        }
    }

    print_string(head);
    return 0;
}

node* insert(node* ptr, char c) {
    node* new_node = new node(c);

    if (!ptr) {
        return new_node;
    }

    if (ptr -> next) {
        ptr -> next -> prev = new_node;
        new_node -> next = ptr -> next;
    }
    ptr -> next = new_node;
    new_node -> prev = ptr;

    return new_node;
}

node* remove(node* ptr) {
    if (ptr -> c == '\0') {
        return ptr;
    }

    node* prev = ptr -> prev;
    if (ptr -> next) {
        ptr -> next -> prev = ptr -> prev;
    }
    prev -> next = ptr -> next;
    delete ptr;

    return prev;
}

node* go_left(node* ptr) {
    if (ptr -> prev) {
        return ptr -> prev;
    }
    return ptr;
}

node* go_right(node* ptr) {
    if (ptr -> next) {
        return ptr -> next;
    }
    return ptr;
}

pair<node*, node*> initialize_string(string& s) {
    node* cursor = new node(0);
    node* head = cursor;
    for (int i = 0; i < (int) s.size(); ++i) {
        cursor = insert(cursor, s[i]);
    }

    return { head, cursor };
}

void print_string(node* head) {
    head = head -> next;
    while (head) {
        cout << (head -> c);
        head = head -> next;
    }
}
