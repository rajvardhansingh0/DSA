#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    return newNode;
}

void printTree(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    for (Node* child : root->children) {
        printTree(child);
    }
}

int main() {
    Node* root = createNode(1);
    root->children.push_back(createNode(2));
    root->children.push_back(createNode(3));
    root->children[0]->children.push_back(createNode(4));
    root->children[0]->children.push_back(createNode(5));
    root->children[1]->children.push_back(createNode(6));

    printTree(root);
    cout << endl;

    return 0;
}