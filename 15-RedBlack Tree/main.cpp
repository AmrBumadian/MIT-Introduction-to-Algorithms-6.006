#include <iostream>
#include <time.h>
#include "RBT.h"
#include "RBT.cpp"

int main() {
    srand(time(0));
    RBT<int> tree;
    for (int i = 0; i < 100; ++i) {
        tree.insert(rand() % 1000);
    }

    auto node = tree.getRoot();
    tree.inorderWalk(node);
    cout << endl;

    for (int i = 0; i < 100; ++i) {
        node = tree.getRoot();
        tree.remove(tree.minimum(node));
        node = tree.getRoot();
        tree.inorderWalk(node);
        cout << endl;
    }
}
