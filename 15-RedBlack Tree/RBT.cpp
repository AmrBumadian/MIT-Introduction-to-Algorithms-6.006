//
// Created by Amr Bumadian
//

#include "RBT.h"
#include <iostream>

using namespace std;


template<typename T>
RBT<T>::RBT() {
    length = 0;
    NIL = new Node<T>();
    root = NIL;
}

template<typename T>
Node<T> *RBT<T>::getRoot() {
    return root;
}

template<typename T>
void RBT<T>::inorderWalk(Node<T> *currentNode) { // print the tree in sorted order
    if (currentNode == NIL) return;
    inorderWalk(currentNode->left); // traverse the left subtree
    cout << currentNode->value << " "; // print the current node
    inorderWalk(currentNode->right); // traverse the right subtree
}

template<typename T>
void RBT<T>::preorderWalk(Node<T> *currentNode) { // print the tree where each node is printed before its subtrees
    if (currentNode == NIL) return;
    cout << currentNode->value << " ";
    preorderWalk(currentNode->left);
    preorderWalk(currentNode->right);
}

template<typename T>
void RBT<T>::postorderWalk(Node<T> *currentNode) { // print the tree where each node is printed after its subtrees
    if (currentNode == NIL) return;
    postorderWalk(currentNode->left);
    postorderWalk(currentNode->right);
    cout << currentNode->value << " ";
}

template<typename T>
Node<T> *RBT<T>::recursiveSearch(Node<T> *currentNode, T value) { // search for value recursively from the root
    if (currentNode == NIL || currentNode->value == value) return currentNode;
    if (value < currentNode->value) {
        // if value is less than the currentNodes value search for value in the left subtree
        return recursiveSearch(currentNode->left, value);
        // if value is less than the currentNodes value search for value in the left subtree
    } else return recursiveSearch(currentNode->right, value);
}

template<typename T>
Node<T> *RBT<T>::iterativeSearch(T value) {
    Node<T> *currentNode = root;
    while (currentNode != NIL &&
           currentNode->value != value) { // while value not found and currentNode not a nullptr
        if (value < currentNode->value) currentNode = currentNode->left; // point to left subtree
        else currentNode = currentNode->right; // point to right subtree
    }
    return currentNode; // holds value or nullptr
}

template<typename T>
Node<T> *RBT<T>::minimum(Node<T> *currentNode) { // find minimum node
    while (currentNode->left != NIL) { // while the subtree has a left child
        currentNode = currentNode->left; // point to that child
    }
    return currentNode; // return the most down-left node in the tree
}

template<typename T>
Node<T> *RBT<T>::maximum(Node<T> *currentNode) { // find maximum node
    while (currentNode->right != NIL) { // while the subtree has a right child
        currentNode = currentNode->right; // point to that child
    }
    return currentNode; // return the most down-right node in the tree
}

template<typename T>
Node<T> *RBT<T>::predecessor(Node<T> *currentNode) { // find the next node in the sorted order
    // if the left subtree is not nullptr, then the predecessor is the maximum element in the left subtree
    if (currentNode->left != NIL) return maximum(currentNode->left);
    // else the predecessor is an ancestor with left child is also an ancestor to the node
    Node<T> *y = currentNode->parent;
    while (y != nullptr && currentNode == y->left) {
        currentNode = y;
        y = y->parent;
    }
    if (y == NIL) return nullptr;
    return y;
}

template<typename T>
Node<T> *RBT<T>::successor(Node<T> *currentNode) { // find the previous node in the sorted order
    // if the right subtree is not nullptr, then the successor is the minimum element in the right subtree
    if (currentNode->right != NIL) return minimum(currentNode->right);
    // else the successor is an ancestor with left child is also an ancestor to the node
    Node<T> *y = currentNode->parent;
    while (y != NIL && currentNode == y->right) {
        currentNode = y;
        y = y->parent;
    }
    return y;
}

template<typename T>
void RBT<T>::leftRotate(Node<T> *currentNode) {
    Node<T> *y = currentNode->right; // set y equal the right child of currentNode
    currentNode->right = y->left; // turn y's left subtree into currentNode's subtree

    if (y->left != NIL)
        y->left->parent = currentNode; // if exists, set the parent to the left subtree to be currentNode

    y->parent = currentNode->parent; // set the parent of y to be the parent of currentNode

    if (currentNode->parent == NIL) root = y;
    else if (currentNode->parent->left == currentNode) currentNode->parent->left = y;
    else currentNode->parent->right = y;

    y->left = currentNode; // put currentNode on y's left
    currentNode->parent = y;
}

template<typename T>
void RBT<T>::rightRotate(Node<T> *currentNode) {
    Node<T> *y = currentNode->left; // set y equal the left child of currentNode
    currentNode->left = y->right; // turn y's right subtree into currentNode's subtree

    if (y->right != NIL)
        y->right->parent = currentNode; // if exists, set the parent to the right subtree to be currentNode

    y->parent = currentNode->parent; // set the parent of y to be the parent of currentNode

    if (currentNode->parent == NIL) root = y;
    else if (currentNode->parent->left == currentNode) currentNode->parent->left = y;
    else currentNode->parent->right = y;

    y->right = currentNode; // put currentNode on y's right
    currentNode->parent = y;
}

template<typename T>
void RBT<T>::insertFixUp(Node<T> *newNode) {
    while (newNode->parent->color) { // as long as it is red
        // if the subtree is the left child of its parent
        if (newNode->parent == newNode->parent->parent->left) {
            auto y = newNode->parent->parent->right;
            // case 1, if y's color is red, make y and its parent black and its grandparent red
            // then move the pointer to its grandparent for the next iteration
            if (y->color) {
                newNode->parent->color = false; // black
                y->color = false; // black
                newNode->parent->parent->color = true; // red
                newNode = newNode->parent->parent;
            } else {
                // case 2, if newNode is the right child of its parent make a left rotation
                // so that the right subtree of this tree is empty prior the right rotation
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotate(newNode);
                }
                // case 3, do the right rotation and change coloring to maintain black-height property
                newNode->parent->color = false; // black
                newNode->parent->parent->color = true; // red
                rightRotate(newNode->parent->parent);
            }
        } else { // symmetric to the above case but if the subtree was the right child of its parent
            auto y = newNode->parent->parent->left;
            if (y->color) {
                newNode->parent->color = false;
                y->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotate(newNode);
                }
                newNode->parent->color = false; // black
                newNode->parent->parent->color = true; // red
                leftRotate(newNode->parent->parent);
            }
        }
    }
    root->color = false;
}

template<typename T>
void RBT<T>::insert(T value) {
    if (root == NIL) { // if the tree is empty
        root = new Node<T>(NIL); // assign the root node to this value
        root->value = value;
        root->color = false;
    } else {
        Node<T> *newNode = new Node<T>(NIL); // create new node
        newNode->value = value;
        Node<T> *currentNode = root;
        Node<T> *currentParent;
        while (currentNode != NIL) { // traverse from the root to find the newNode position
            currentParent = currentNode; // trailer node for the parent of the currentNode
            if (value < currentNode->value) currentNode = currentNode->left; // traverse the left subtree
            else currentNode = currentNode->right; // traverse the right subtree
        }
        newNode->parent = currentParent; // the newNode parent is the trailer node
        if (value < currentParent->value) currentParent->left = newNode;
        else currentParent->right = newNode;

        insertFixUp(newNode);
    }
    ++length;
}

template<typename T>
void RBT<T>::insert(Node<T> *newNode) { // overloading
    if (root == NIL) {
        root = newNode;
        newNode->color = false;
    } else {
        Node<T> *currentNode = root;
        Node<T> *currentParent;
        while (currentNode != NIL) {
            currentParent = currentNode;
            if (newNode->value < currentNode->value) currentNode = currentNode->left;
            else currentNode = currentNode->right;
        }
        if (newNode->value < currentParent->value) currentParent->left = newNode;
        else currentParent->right = newNode;

        insertFixUp(newNode);
    }
    ++length;
}


template<typename T>
void RBT<T>::transPlant(Node<T> *node, Node<T> *replacement) { // replace node with another node
    if (node->parent == NIL) root = replacement;
    else if (node == node->parent->left) node->parent->left = replacement;
    else node->parent->right = replacement;
    replacement->parent = node->parent;
}

template<typename T>
void RBT<T>::deleteFixUp(Node<T> *currentNode) {
    Node<T> *y;
    while (currentNode != root && !currentNode->color) {
        if (currentNode == currentNode->parent->left) {
            y = currentNode->parent->right;
            if (y->color) {
                y->color = false;
                currentNode->parent->color = true;
                leftRotate(currentNode->parent);
                y = currentNode->parent->right;
            }
            if (!y->left->color && !y->right->color) {
                y->color = true;
                currentNode = currentNode->parent;
            } else {
                if (!y->right->color) {
                    y->left->color = false;
                    y->color = true;
                    rightRotate(y);
                    y = currentNode->parent->right;
                }
                y->color = currentNode->parent->color;
                currentNode->parent->color = false;
                y->right->color = false;
                leftRotate(currentNode->parent);
                currentNode = root;
            }
        } else {
            y = currentNode->parent->left;
            if (y->color) {
                y->color = false;
                currentNode->parent->color = true;
                rightRotate(currentNode->parent);
                y = currentNode->parent->left;
            }
            if (!y->right->color && !y->left->color) {
                y->color = true;
                currentNode = currentNode->parent;
            } else {
                if (!y->left->color) {
                    y->right->color = false;
                    y->color = true;
                    leftRotate(y);
                    y = currentNode->parent->left;
                }
                y->color = currentNode->parent->color;
                currentNode->parent->color = false;
                y->left->color = false;
                rightRotate(currentNode->parent);
                currentNode = root;
            }
        }
    }
    currentNode->color = false;
}

template<typename T>
void RBT<T>::remove(Node<T> *z) {
    Node<T> *x, *y = z;
    bool originalColor = z->color;
    if (z->left == NIL) {
        x = z->right;
        transPlant(z, x);
    } else if (z->right == NIL) {
        x = z->left;
        transPlant(z, x);
    } else {
        y = minimum(z->right);
        originalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transPlant(y, x);
            y->right = z->right;
            y->right->parent = y;
        }
        transPlant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (!originalColor) deleteFixUp(x);
    delete z;
    --length;
}

template<typename T>
RBT<T>::~RBT() {
    destruct(root);
}

template<typename T>
void RBT<T>::destruct(Node<T> *currentNode) { // post order traversal to delete each node
    if (currentNode == NIL) return;
    destruct(currentNode->left); // delete the left subtree
    destruct(currentNode->right); // delete the right subtree
    delete currentNode; // delete currentNode
    delete NIL;
}