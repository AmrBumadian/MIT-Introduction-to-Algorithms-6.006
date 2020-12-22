//
// Created by Amr Bumadian
//

#include "BST.h"
#include <iostream>

using namespace std;

template<typename T>
BST<T>::BST() {
    length = 0;
    root = nullptr;
}

template<typename T>
Node<T> *BST<T>::getRoot() {
    return root;
}

template<typename T>
void BST<T>::inorderWalk(Node<T> *currentNode) { // print the tree in sorted order
    if (currentNode == nullptr) return;
    inorderWalk(currentNode->left); // traverse the left subtree
    cout << currentNode->value << " "; // print the current node
    inorderWalk(currentNode->right); // traverse the right subtree
}

template<typename T>
void BST<T>::preorderWalk(Node<T> *currentNode) { // print the tree where each node is printed before its subtrees
    if (currentNode == nullptr) return;
    cout << currentNode->value << " ";
    preorderWalk(currentNode->left);
    preorderWalk(currentNode->right);
}

template<typename T>
void BST<T>::postorderWalk(Node<T> *currentNode) { // print the tree where each node is printed after its subtrees
    if (currentNode == nullptr) return;
    postorderWalk(currentNode->left);
    postorderWalk(currentNode->right);
    cout << currentNode->value << " ";
}

template<typename T>
Node<T> *BST<T>::recursiveSearch(Node<T> *currentNode, T value) { // search for value recursively from the root
    if (currentNode == nullptr || currentNode->value == value) return currentNode;
    if (value < currentNode->value) {
        // if value is less than the currentNodes value search for value in the left subtree
        return recursiveSearch(currentNode->left, value);
        // if value is less than the currentNodes value search for value in the left subtree
    } else return recursiveSearch(currentNode->right, value);
}

template<typename T>
Node<T> *BST<T>::iterativeSearch(T value) {
    Node<T> *currentNode = root;
    while (currentNode != nullptr &&
           currentNode->value != value) { // while value not found and currentNode not a nullptr
        if (value < currentNode->value) currentNode = currentNode->left; // point to left subtree
        else currentNode = currentNode->right; // point to right subtree
    }
    return currentNode; // holds value or nullptr
}

template<typename T>
Node<T> *BST<T>::minimum(Node<T> *currentNode) { // find minimum node
    while (currentNode->left != nullptr) { // while the subtree has a left child
        currentNode = currentNode->left; // point to that child
    }
    return currentNode; // return the most down-left node in the tree
}

template<typename T>
Node<T> *BST<T>::maximum(Node<T> *currentNode) { // find maximum node
    while (currentNode->right != nullptr) { // while the subtree has a right child
        currentNode = currentNode->right; // point to that child
    }
    return currentNode; // return the most down-right node in the tree
}

template<typename T>
Node<T> *BST<T>::predecessor(Node<T> *currentNode) { // find the next node in the sorted order
    // if the left subtree is not nullptr, then the predecessor is the maximum element in the left subtree
    if (currentNode->left != nullptr) return maximum(currentNode->left);
    // else the predecessor is an ancestor with left child is also an ancestor to the node
    Node<T> *y = currentNode->parent;
    while (y != nullptr && currentNode == y->left) {
        currentNode = y;
        y = y->parent;
    }
    if (y == nullptr) return nullptr;
    return y;
}

template<typename T>
Node<T> *BST<T>::successor(Node<T> *currentNode) { // find the previous node in the sorted order
    // if the right subtree is not nullptr, then the successor is the minimum element in the right subtree
    if (currentNode->right != nullptr) return minimum(currentNode->right);
    // else the successor is an ancestor with left child is also an ancestor to the node
    Node<T> *y = currentNode->parent;
    while (y != nullptr && currentNode == y->right) {
        currentNode = y;
        y = y->parent;
    }
    return y;
}

template<typename T>
void BST<T>::insert(T value) {
    if (root == nullptr) { // if the tree is empty
        root = new Node<T>; // assign the root node to this value
        root->value = value;
    } else {
        Node<T> *newNode = new Node<T>; // create new node
        newNode->value = value;
        Node<T> *currentNode = root;
        Node<T> *currentParent;
        while (currentNode != nullptr) { // traverse from the root to find the newNode position
            currentParent = currentNode; // trailer node for the parent of the currentNode
            if (value < currentNode->value) currentNode = currentNode->left; // traverse the left subtree
            else currentNode = currentNode->right; // traverse the right subtree
        }
        newNode->parent = currentParent; // the newNode parent is the trailer node
        if (value < currentParent->value) currentParent->left = newNode;
        else currentParent->right = newNode;
    }
    ++length;
}

template<typename T>
void BST<T>::insert(Node<T> *newNode) { // overloading
    if (root == nullptr) {
        root = newNode;
    } else {
        Node<T> *currentNode = root;
        Node<T> *currentParent;
        while (currentNode != nullptr) {
            currentParent = currentNode;
            if (newNode->value < currentNode->value) currentNode = currentNode->left;
            else currentNode = currentNode->right;
        }
        if (newNode->value < currentParent->value) currentParent->left = newNode;
        else currentParent->right = newNode;
    }
    ++length;
}

template<typename T>
void BST<T>::transPlant(Node<T> *node, Node<T> *replacement) { // replace node with another node
    if (node->parent == nullptr) root = replacement;
    else if (node == node->parent->left) node->parent->left = replacement;
    else node->parent->right = replacement;
    if (replacement != nullptr) replacement->parent = node->parent;
}

template<typename T>
void BST<T>::remove(Node<T> *currentNode) {
    Node<T> *replacement;
        // if the left subtree is empty replace the node with its right subtree
    if (currentNode->left == nullptr)
        transPlant(currentNode, currentNode->right);

        // else if the left subtree is not empty && right subtree is empty replace the node with its left subtree
    else if (currentNode->right == nullptr)
        transPlant(currentNode, currentNode->left);

        // else since it has both children
    else {
        Node<T> *success = minimum(currentNode->right); // find the successor
        if (success->parent != currentNode) { // if the successor is not the right child of the node
            transPlant(success,
                       success->right); // replace the successor node with its right child, it has no left child
            success->right = currentNode->right; // the successor right child is currentNode right child
            success->right->parent = success; // the successor right-child's parent is the successor
        }
        transPlant(currentNode, success); // replace currentNode with the successor
        success->left = currentNode->left;
        success->left->parent = success;
    }
    delete currentNode; // free the memory of currentNode
    --length;
}

template<typename T>
BST<T>::~BST() {
    destruct(root);
}

template<typename T>
void BST<T>::destruct(Node<T> *currentNode) { // post order traversal to delete each node
    if (currentNode == nullptr) return;
    destruct(currentNode->left); // delete the left subtree
    destruct(currentNode->right); // delete the right subtree
    delete currentNode; // delete currentNode
}