
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
        if (target == parent->left) { // zig
            parent->left = subtree = target->right;
            target->right = parent;
        } else { // zag
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
                if ((grandparent->left == parent) == (parent->left == target)) { // zig-zig or zag-zag
                    rotate(parent);
                } else { // zig-zag or zag-zig
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
        // implement
    }

    void inorder() {
        if (root) {
            inorder(root);
        }
        cout << '\n';
    }

    void inorder(node<T> *target) {
        if (target->left) {
            inorder(target->left);
        }
        cout << target->value << ' ';
        if (target->right) {
            inorder(target->right);
        }
    }
};

int main() {
    // implement
}
