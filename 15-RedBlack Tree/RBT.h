//
// Created by Amr Bumadian
//

#ifndef BST_BST_H
#define BST_BST_H

template<typename T>
class Node {
public:
    T value;
    bool color;
    Node *parent, *left, *right;

    Node() {
        color = false; // black
        parent = left = right = nullptr;
    }

    Node(Node<T> *NIL) {
        color = true; // red
        parent = left = right = NIL;
    }

};

template<typename T>
class RBT {
private:
    Node<T> *root, *NIL;
    int length;

    void destruct(Node<T> *currentNode);

    void transPlant(Node<T> *node, Node<T> *replacement);

    void leftRotate(Node<T> *currentNode);

    void rightRotate(Node<T> *currentNode);

    void insertFixUp(Node<T> *currentNode);

    void deleteFixUp(Node<T> *currentNode);


public:

    RBT();

    Node<T> *getRoot();

    void inorderWalk(Node<T> *currentNode);

    void preorderWalk(Node<T> *currentNode);

    void postorderWalk(Node<T> *currentNode);

    Node<T> *recursiveSearch(Node<T> *currentNode, T value);

    Node<T> *iterativeSearch(T value);

    Node<T> *minimum(Node<T> *currentNode);

    Node<T> *maximum(Node<T> *currentNode);

    Node<T> *predecessor(Node<T> *currentNode);

    Node<T> *successor(Node<T> *currentNode);

    void insert(T value);

    void insert(Node<T> *newNode);

    void remove(Node<T> *z);

    ~RBT();
};


#endif //BST_BST_H
