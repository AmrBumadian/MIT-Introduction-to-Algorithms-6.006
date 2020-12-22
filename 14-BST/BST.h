//
// Created by Amr Bumadian
//

#ifndef BST_BST_H
#define BST_BST_H

template<typename T>
class Node {
public:
    T value;
    Node *parent, *left, *right;

    Node() {
        parent = left = right = nullptr;
    }
};

template<typename T>
class BST {
private:
    Node<T> *root;
    int length;

    void destruct(Node<T> *currentNode);

    void transPlant(Node<T> *node, Node<T> *replacement);

public:

    BST();

    Node<T> *getRoot();

    void inorderWalk(Node<T> *currentNode);

    void preorderWalk(Node<T> *currentNode);

    void postorderWalk(Node<T> *currentNode);

    Node<T> *recursiveSearch(Node<T> *currentNode, T value);

    Node<T> *iterativeSearch(T value);

    Node<T> *minimum(Node<T>* currentNode);

    Node<T> *maximum(Node<T>* currentNode);

    Node<T> *predecessor(Node<T> *currentNode);

    Node<T> *successor(Node<T> *currentNode);

    void insert(T value);

    void insert(Node<T> *newNode);

    void remove(Node<T> *currentNode);

    ~BST();
};


#endif //BST_BST_H
