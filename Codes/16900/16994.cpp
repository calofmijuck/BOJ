
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node {
public:
    node *left, *right, *parent;
    T value;
    int size;

    node(void) : left(0), right(0), parent(0), size(0) {}

    node(const T &value) : left(0), right(0), parent(0), value(value), size(0) {}
};

template <typename T>
class splay_tree {
    node<T> *root;

public:
    void update(node<T> *target) {
        target->size = 1;
        if (target->left) {
            target->size += target->left->size;
        }
        if (target->right) {
            target->size += target->right->size;
        }
    }

    void rotate(node<T> *target) {
        node<T> *parent = target->parent;
        node<T> *subtree;
        if (target == parent->left) {
            parent->left = subtree = target->right;
            target->right = parent;
        } else {
            parent->right = subtree = target->left;
            target->left = parent;
        }
        if (subtree) {
            subtree->parent = parent;
        }
        target->parent = parent->parent;
        parent->parent = target;

        if (target->parent) {
            if (parent == target->parent->left) {
                target->parent->left = target;
            } else {
                target->parent->right = target;
            }
        } else {
            root = target;
        }
        update(parent);
        update(target);
    }

    void splay(node<T> *target) {
        while (target->parent) {
            node<T> *parent = target->parent, *grandparent = parent->parent;
            if (grandparent) {
                if ((grandparent->left == parent) == (parent->left == target)) {
                    rotate(parent);
                } else {
                    rotate(target);
                }
            }
            rotate(target);
        }
    }

    void splay_kth(int k) {
        node<T> *target = root;
        while (true) {
            while (target->left && target->left->size > k) {
                target = target->left;
            }
            if (target->left) {
                k -= target->left->size;
            }
            if (k == 0) {
                break;
            }
            k--;
            target = target->right;
        }
        splay(target);
    }

    void splay_interval(int left, int right) {
        splay_kth(left - 1);

        node<T> *tmp = root;
        root = root->right;
        root->parent = nullptr;
        splay_kth(right - left + 1);
        tmp->right = root;
        root->parent = tmp;
        root = tmp;
    }

    void init(string &s) {
        int n = s.size();

        node<T> *new_node = new node('\0');
        new_node->size = n + 2;

        root = new_node;
        for (int i = 0; i <= n; i++) {
            new_node->right = new node(s[i]);
            new_node->right->parent = new_node;
            new_node = new_node->right;
            new_node->size = n + 1 - i;
        }
    }
    void query() {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            splay_interval(x + 1, y + 1);

            node<T> *target = root->right->left;
            target->parent = root->right->left = nullptr;

            update(root->right);
            update(root);

            splay_kth(1);

            root->left->right = target;
            target->parent = root->left;

            update(root->left);
            update(root);
        } else if (op == 2) {
            cin >> x >> y;
            splay_interval(x + 1, y + 1);

            node<T> *target = root->right->left;
            target->parent = root->right->left = nullptr;

            update(root->right);
            update(root);

            splay_kth(root->size - 2);

            root->right->left = target;
            target->parent = root->right;

            update(root->right);
            update(root);
        } else {
            cin >> x;
            splay_kth(x + 1);
            cout << root->value << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    splay_tree<char> tree;
    tree.init(s);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        tree.query();
    }
}
