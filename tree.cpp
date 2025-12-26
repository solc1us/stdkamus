#include <iostream>
#include "tree.h"

using namespace std;

void displayMenu() {
    cout << "==========================" << endl;
    cout << "Menu:" << endl;
    cout << "1. Masukkan kata" << endl;
    cout << "2. Cari kata" << endl;
    cout << "3. Tampilkan kamus lengkap" << endl;
    cout << "4. Hapus kata" << endl;
    cout << "5. Filter kata berdasarkan huruf awal" << endl;
    cout << "6. Banyak kata dalam kamus" << endl;
    cout << "7. Kata pertama" << endl;
    cout << "8. Kata terakhir" << endl;
    cout << "9. Kata yang sering dicari" << endl;
    cout << "0. Keluar" << endl;
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

static bool hasInitial(adrNode root, char initial) {
    if (root == nullptr) {
        return false;
    }

    char c = root->info.empty() ? '\0' : root->info[0];
    bool match = (root->info.size() > 1) && (c == initial);

    return hasInitial(root->left, initial) || match || hasInitial(root->right, initial);
}

static void printByInitial(adrNode root, char initial) {
    if (root == nullptr) {
        return;
    }

    printByInitial(root->left, initial);

    if (!root->info.empty() && root->info.size() > 1) {
        char c = root->info[0];
        if (c == initial) {
            cout << "  - " << root->info << endl;
        }
    }

    printByInitial(root->right, initial);
}

void displayDictionary(adrNode root) {
    for (char initial = 'A'; initial <= 'Z'; ++initial) {
        cout << initial << ":" << endl;
        if (hasInitial(root, initial)) {
            printByInitial(root, initial);
        } else {
            cout << "  No words starting with " << initial << endl;
        }
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
        return "";
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
        return "";
    }
    adrNode current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->info;
}
