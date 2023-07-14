#ifndef bst_h
#define bst_h

#include <iostream>
#include <iomanip>

#define BST_NodeType int

class Node {
public:
    BST_NodeType value;
    Node(BST_NodeType);
    Node* left = nullptr;
    Node* right = nullptr;
    ~Node() { std::cout << "Killed " << value << std::endl; }
};

Node::Node(BST_NodeType tmp) {
    value = tmp;
}

class BST {
private:
    Node* root = nullptr;
    void insert(BST_NodeType, Node*);
    void printDFS(Node*, int = 0);
    void printPreorder(Node*);
    void printInorder(Node*);
    void printPostorder(Node*);
    void printGraphical(Node*, int = 0);
    void kill(Node*);

public:
    void insert(BST_NodeType);
    void printDFS();
    void printPreorder();
    void printInorder();
    void printPostorder();
    void printGraphical();
    ~BST();
};

void BST::insert(BST_NodeType value) {
    if (root != nullptr)
        insert(value, root);
    else {
        root = new Node(value);
    }
}

void BST::insert(BST_NodeType value, Node* newRoot) {
    Node* nextPosition = nullptr;
    BST_NodeType rootVal = newRoot->value;
    if (value > rootVal && newRoot->right == nullptr) {
        newRoot->right = new Node(value);
        return;
    }
    if (value <= rootVal && newRoot->left == nullptr) {
        newRoot->left = new Node(value);
        return;
    }
    insert(value, value > rootVal ? newRoot->right : newRoot->left);
}

void BST::printDFS() {
    std::cout << std::setfill('-');
    printDFS(root);
}

void BST::printDFS(Node* newRoot, int level) {
    if (newRoot == nullptr) {
        std::cout << 'X' << std::endl;
        return;
    }
    std::cout << newRoot->value << std::endl;
    std::cout << std::setw(level + 1);
    std::cout << "L:";
    printDFS(newRoot->left, level + 1);
    std::cout << std::setw(level + 1);
    std::cout << "R:";
    printDFS(newRoot->right, level + 1);
}

void BST::printPreorder() {
    printPreorder(root);
}

void BST::printPreorder(Node* newRoot) {
    if (newRoot == nullptr)
        return;
    std::cout << newRoot->value << std::endl;
    printPreorder(newRoot->left);
    printPreorder(newRoot->right);
}

void BST::printInorder() {
    printInorder(root);
}

void BST::printInorder(Node* newRoot) {
    if (newRoot == nullptr)
        return;
    printInorder(newRoot->left);
    std::cout << newRoot->value << std::endl;
    printInorder(newRoot->right);
}

void BST::printPostorder() {
    printPostorder(root);
}

void BST::printPostorder(Node* newRoot) {
    if (newRoot == nullptr)
        return;
    printPostorder(newRoot->left);
    printPostorder(newRoot->right);
    std::cout << newRoot->value << std::endl;
}

void BST::printGraphical() {
    std::cout << std::setfill(' ');
    printGraphical(root);
}

void BST::printGraphical(Node* newRoot, int level) {
    if (newRoot == nullptr) {
        std::cout << std::setw(level * 3) << 'X' << std::endl;
        return;
    }
    printGraphical(newRoot->right, level + 1);
    std::cout << std::setw(level * 3) << newRoot->value << std::endl;
    printGraphical(newRoot->left, level + 1);
}

BST::~BST() {
    kill(root);
    std::cout << "Killed BST" << std::endl;
}

void BST::kill(Node* newRoot) {
    if (!newRoot)
        return;
    kill(newRoot->left);
    kill(newRoot->right);
    delete newRoot;
}

#endif
