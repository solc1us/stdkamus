#ifndef KAMUS_H_INCLUDED
#define KAMUS_H_INCLUDED

using namespace std;

typedef string infotype;
typedef struct Node *adrNode;

struct Node {
  infotype info;
  adrNode left;
  adrNode right;
};

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

#endif // KAMUS_H_INCLUDED
