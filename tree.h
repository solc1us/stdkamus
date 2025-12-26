#ifndef KAMUS_H_INCLUDED
#define KAMUS_H_INCLUDED

#include <string>

using namespace std;

struct isiInfo {
    string word;
    string meaning;
    int searchCount;
};

typedef isiInfo infotype;
typedef struct Node *adrNode;

struct Node {
  infotype info;
  adrNode left;
  adrNode right;
};

inline bool operator<(const infotype& a, const infotype& b) {
    return a.word < b.word;
}
inline bool operator>(const infotype& a, const infotype& b) {
    return a.word > b.word;
}
inline bool operator==(const infotype& a, const infotype& b) {
    return a.word == b.word;
}
inline bool operator!=(const infotype& a, const infotype& b) {
    return !(a == b);
}

void displayMenu();
void createTree(adrNode &root);
adrNode createNode(infotype x);
void insertNode(adrNode &root, adrNode p);
adrNode searchNode(adrNode root, infotype x);
void displayTreeAscending(adrNode root);
void displayTreeDescending(adrNode root);
void deleteNode(adrNode &root, infotype x);
void filterNodes(adrNode root, char initial);
int countNodes(adrNode root);
infotype getMinValue(adrNode root);
infotype getMaxValue(adrNode root);
void displayDictionary(adrNode root);
void displayMostSearched(adrNode root);

#endif // KAMUS_H_INCLUDED
