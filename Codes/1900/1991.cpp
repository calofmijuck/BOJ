#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

Node* tree[30];

Node* newNode(char data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> left = node -> right = NULL;
    return node;
}

void insert(char data, char left, char right) {
    if(tree[data - 'A'] == NULL) tree[data - 'A'] = newNode(data);
    if(left != '.') {
        if(tree[left - 'A'] == NULL) tree[left - 'A'] = newNode(left);
        tree[data - 'A'] -> left = tree[left - 'A'];
    }
    if(right != '.') {
        if(tree[right - 'A'] == NULL) tree[right - 'A'] = newNode(right);
        tree[data - 'A'] -> right = tree[right - 'A'];
    }
}

void preOrder(Node* root) {
    if(root == NULL) return;
    printf("%c", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root -> left);
    printf("%c", root -> data);
    inOrder(root -> right);
}

void postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%c", root -> data);
}

int main() {
    int n;
    string s1, s2, s3;
    scanf("%d", &n);
    while(n--) {
        cin >> s1 >> s2 >> s3;
        insert(s1.at(0), s2.at(0), s3.at(0));
    }
    preOrder(tree[0]); puts("");
    inOrder(tree[0]); puts("");
    postOrder(tree[0]);
    return 0;
}
