#include <bits/stdc++.h>
using namespace std;

class AVLTree {
    struct Node {
        int key;
        Node *left, *right;
        int height, size;
        Node(int k) : key(k), left(NULL), right(NULL), height(1), size(1) {}
    };

    Node *root;

    int height(Node *n) {
        return n ? n->height : 0;
    }

    int size(Node *n) {
        return n ? n->size : 0;
    }

    int balanceFactor(Node *n) {
        return height(n->left) - height(n->right);
    }

    void update(Node *n) {
        if (n) {
            n->height = 1 + max(height(n->left), height(n->right));
            n->size = 1 + size(n->left) + size(n->right);
        }
    }

    Node* rotateRight(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        update(y);
        update(x);
        return x;
    }

    Node* rotateLeft(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        update(x);
        update(y);
        return y;
    }

    Node* balance(Node *n) {
        update(n);
        if (balanceFactor(n) > 1) {
            if (balanceFactor(n->left) < 0) {
                n->left = rotateLeft(n->left);
            }
            return rotateRight(n);
        }
        if (balanceFactor(n) < -1) {
            if (balanceFactor(n->right) > 0) {
                n->right = rotateRight(n->right);
            }
            return rotateLeft(n);
        }
        return n;
    }

    Node* insert(Node *n, int key) {
        if (!n) return new Node(key);
        if (key < n->key) n->left = insert(n->left, key);
        else if (key > n->key) n->right = insert(n->right, key);
        else return n;  // No duplicates allowed
        return balance(n);
    }

    Node* minNode(Node *n) {
        Node *current = n;
        while (current->left) current = current->left;
        return current;
    }

    Node* remove(Node *root, int key) {
        if (!root) return root;
        if (key < root->key) root->left = remove(root->left, key);
        else if (key > root->key) root->right = remove(root->right, key);
        else {
            if (!root->left || !root->right) {
                Node *temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = NULL;
                } else *root = *temp;
                delete temp;
            } else {
                Node *temp = minNode(root->right);
                root->key = temp->key;
                root->right = remove(root->right, temp->key);
            }
        }
        if (!root) return root;
        return balance(root);
    }

    bool find(Node *n, int key) {
        if (!n) return false;
        if (key < n->key) return find(n->left, key);
        if (key > n->key) return find(n->right, key);
        return true;
    }

    int orderOfKey(Node *n, int key) {
        if (!n) return 0;
        if (key < n->key) return orderOfKey(n->left, key);
        if (key > n->key) return 1 + size(n->left) + orderOfKey(n->right, key);
        return size(n->left);
    }

    Node* getByOrder(Node *n, int k) {
        if (!n) return NULL;
        int leftSize = size(n->left);
        if (k < leftSize) return getByOrder(n->left, k);
        if (k > leftSize) return getByOrder(n->right, k - leftSize - 1);
        return n;
    }

public:
    AVLTree() : root(NULL) {}

    bool find(int key) {
        return find(root, key);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    int orderOfKey(int key) {
        return orderOfKey(root, key);
    }

    int getByOrder(int k) {
        Node *n = getByOrder(root, k);
        return n ? n->key : -1;
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    cout << tree.find(10) << endl;  // 1
    cout << tree.find(25) << endl;  // 0
    cout << tree.orderOfKey(25) << endl;  // 2
    cout << tree.getByOrder(1) << endl;  // 20
    tree.remove(10);
    cout << tree.find(10) << endl;  // 0
    return 0;
}
