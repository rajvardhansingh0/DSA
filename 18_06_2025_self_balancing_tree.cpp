#include <iostream>

enum class Color { RED, BLACK };

struct Node {
    int data;
    Node *left, *right, *parent;
    Color color;

    Node(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr), color(Color::RED) {}
};

class SelfBalancingTree {
private:
    Node *root;

    void rotateLeft(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != nullptr) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node *x) {
        Node *y = x->left;
        x->left = y->right;
        if (y->right != nullptr) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node *k) {
        while (k != nullptr && k != root && k->parent->color == Color::RED) {
            if (k->parent == k->parent->parent->left) {
                Node *y = k->parent->parent->right;
                if (y != nullptr && y->color == Color::RED) {
                    k->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    k->parent->parent->color = Color::RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->color = Color::BLACK;
                    k->parent->parent->color = Color::RED;
                    rotateRight(k->parent->parent);
                }
            } else {
                Node *y = k->parent->parent->left;
                if (y != nullptr && y->color == Color::RED) {
                    k->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    k->parent->parent->color = Color::RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->color = Color::BLACK;
                    k->parent->parent->color = Color::RED;
                    rotateLeft(k->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }


    Node* findMin(Node* node){
        while(node->left != nullptr) node = node->left;
        return node;
    }

    Node* treeSuccessor(Node* node){
        if(node->right != nullptr) return findMin(node->right);
        Node* parent = node->parent;
        while(parent != nullptr && node == parent->right){
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }

    void fixDelete(Node* node){
        while(node != root && (node == nullptr || node->color == Color::BLACK)){
            if(node == node->parent->left){
                Node* sibling = node->parent->right;
                
                
                
                
            }
            else{

            }
        }
    }

public:
    SelfBalancingTree() : root(nullptr) {}

    void insert(int data) {
        Node *node = new Node(data);
        Node *y = nullptr;
        Node *x = root;
        while (x != nullptr) {
            y = x;
            if (node->data < x->data) x = x->left;
            else x = x->right;
        }
        node->parent = y;
        if (y == nullptr) root = node;
        else if (node->data < y->data) y->left = node;
        else y->right = node;
        fixInsert(node);
    }

    void remove(int data){

    }
};

int main() {}