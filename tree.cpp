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
    p->info.searchCount = 0;
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

static bool isHeaderNode(const infotype& info) {
    return info.word.size() == 1 &&
           info.word[0] >= 'A' && info.word[0] <= 'Z';
}

static void findMostSearched(adrNode root, adrNode &best) {
    if (root == nullptr) return;

    findMostSearched(root->left, best);

    if (!isHeaderNode(root->info)) {
        if (best == nullptr || root->info.searchCount > best->info.searchCount) {
            best = root;
        }
    }

    findMostSearched(root->right, best);
}

void displayMostSearched(adrNode root) {
    adrNode best = nullptr;
    findMostSearched(root, best);

    if (best == nullptr || best->info.searchCount == 0) {
        cout << "Belum ada kata yang sering dicari." << endl;
        return;
    }

    cout << "Kata yang paling sering dicari:" << endl;
    cout << "Kata : " << best->info.word << endl;
    cout << "Arti : " << best->info.meaning << endl;
    cout << "Dicari sebanyak: " << best->info.searchCount << "x" << endl;
}


static bool hasInitial(adrNode root, char initial) {
    if (root == nullptr) return false;

    const string &w = root->info.word;

    if (!isHeaderNode(root->info) && w.size() > 1 && w[0] == initial)
        return true;

    return hasInitial(root->left, initial) || hasInitial(root->right, initial);
}

static void printByInitial(adrNode root, char initial, bool &firstPrinted) {
    if (root == nullptr) return;

    printByInitial(root->left, initial, firstPrinted);

    if (!isHeaderNode(root->info)) {
        const string &w = root->info.word;
        if (!w.empty() && (char)toupper((unsigned char)w[0]) == initial) {
            if (!firstPrinted) {
                cout << ", ";
            }
            cout << w;
            firstPrinted = false;
        }
    }

    printByInitial(root->right, initial, firstPrinted);
}


void displayDictionary(adrNode root) {
    for (char initial = 'A'; initial <= 'Z'; ++initial) {
        cout << initial << ": ";
        bool firstPrinted = true;
        printByInitial(root, initial, firstPrinted);
        cout << endl;
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
    bool firstPrinted = true;
    printByInitial(root, initial, firstPrinted);
}


int countNodes(adrNode root) {
    if (root == nullptr) return 0;

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    int self = isHeaderNode(root->info) ? 0 : 1;

    return left + self + right;
}

infotype getMinValue(adrNode root) {
    infotype empty = {"", ""};
    if (root == nullptr) return empty;

    infotype leftMin = getMinValue(root->left);
    if (!leftMin.word.empty()) return leftMin;
    if (!isHeaderNode(root->info)) return root->info;

    return getMinValue(root->right);
}



infotype getMaxValue(adrNode root) {
    infotype empty = {"", ""};
    if (root == nullptr) return empty;

    infotype rightMax = getMaxValue(root->right);
    if (!rightMax.word.empty()) return rightMax;
    if (!isHeaderNode(root->info)) return root->info;

    return getMaxValue(root->left);
}


