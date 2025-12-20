#include <iostream>
#include "tree.h"

using namespace std;

void displayMenu() {
    cout << "==========================" << endl;
    cout << "Menu:" << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Display Tree" << endl;
    cout << "4. Delete Node" << endl;
    cout << "5. Filter Nodes by Initial" << endl;
    cout << "6. Count Nodes" << endl;
    cout << "7. Get Min Value" << endl;
    cout << "8. Get Max Value" << endl;
    cout << "9. Exit" << endl;
}

void createTree(adrNode &root) {
    root = nullptr;
}

adrNode createNode(infotype x) {
    adrNode p = new Node;
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertNode(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else if (p->info < root->info) {
        insertNode(root->left, p);
    } else {
        insertNode(root->right, p);
    }
}

adrNode searchNode(adrNode root, infotype x) {
    if (root == nullptr) {
        return nullptr;
    } else if (x < root->info) {
        return searchNode(root->left, x);
    } else if (x > root->info) {
        return searchNode(root->right, x);
    }
    return root;
}

void displayTreeAscending(adrNode root) {
    if (root != nullptr) {
        displayTreeAscending(root->left);
        cout << root->info << " ";
        displayTreeAscending(root->right);
    }
}

void displayTreeDescending(adrNode root) {
    if (root != nullptr) {
        displayTreeDescending(root->right);
        cout << root->info << " ";
        displayTreeDescending(root->left);
    }
}

void deleteNode(adrNode &root, infotype x) {
    if (root == nullptr) {
        return;
    }
    if (x < root->info) {
        deleteNode(root->left, x);
    } else if (x > root->info) {
        deleteNode(root->right, x);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            adrNode temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            adrNode temp = root;
            root = root->left;
            delete temp;
        } else {
            adrNode successorParent = root;
            adrNode successor = root->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            root->info = successor->info;
            if (successorParent != root) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }
            delete successor;
        }
    }
}

void filterNodes(adrNode root, char initial) {
    if (root != nullptr) {
        filterNodes(root->left, initial);
        if (!root->info.empty() && root->info[0] == initial) {
            cout << root->info << " ";
        }
        filterNodes(root->right, initial);
    }
}

int countNodes(adrNode root) {
    int count = 0;
    if (root == nullptr) {
        return 0;
    }
    count += countNodes(root->left);
    count += 1;
    count += countNodes(root->right);
    return count;
}

infotype getMinValue(adrNode root) {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
    }
    adrNode current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->info;
}

infotype getMaxValue(adrNode root) {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
    }
    adrNode current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->info;
}
