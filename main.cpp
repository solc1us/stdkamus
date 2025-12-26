#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    adrNode root;
    createTree(root);

    infotype internalNodes[] = {{"A", ""}, {"B", ""}, {"C", ""}, {"D", ""}, {"E", ""}, {"F", ""}, {"G", ""}, {"H", ""}, {"I", ""}, {"J", ""}, {"K", ""}, {"L", ""}, {"M", ""}, {"N", ""}, {"O", ""}, {"P", ""}, {"Q", ""}, {"R", ""}, {"S", ""}, {"T", ""}, {"U", ""}, {"V", ""}, {"W", ""}, {"X", ""}, {"Y", ""}, {"Z", ""}};
    for (int i = 0; i < 26; i++) {
        adrNode newNode = createNode(internalNodes[i]);
        insertNode(root, newNode);
    }
    infotype words[] = {{"Apple", ""}, {"Zebra", ""}, {"Banana", ""}, {"Cherry", ""}, {"Date", ""}, {"Fig", ""}, {"Sour", ""}, {"Raspberry", ""}, {"Lemon", ""}, {"Mango", ""}, {"Nectarine", ""}};
    for (int i = 0; i < 11; i++) {
        adrNode newNode = createNode(words[i]);
        insertNode(root, newNode);
    }

    int choice = -1;
    while (choice != 0)
    {

        displayMenu();

        cout << "Pilih menu: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Masukkan node: ";
            infotype info;
            cin >> info.word;
            adrNode newNode = createNode(info);
            insertNode(root, newNode);
            break;
        }
        case 2:
        {
            cout << "Masukkan kata yang ingin dicari: ";
            infotype searchValue;
            cin >> searchValue.word;
            adrNode foundNode = searchNode(root, searchValue);
            if (foundNode != nullptr)
            {
                cout << "Kata " << searchValue.word << " ditemukan." << endl;
            }
            else
            {
                cout << "Kata " << searchValue.word << " tidak ditemukan." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Isi kamus:" << endl;
            displayDictionary(root);
            break;
        }
        case 4:
        {
            cout << "Masukkan kata yang ingin dihapus: ";
            infotype deleteValue.word;
            cin >> deleteValue.word;
            deleteNode(root, deleteValue.word);
            cout << "Kata " << deleteValue.word << " telah dihapus (jika ada)." << endl;
            break;
        }
        case 5:
        {
            cout << "Masukkan inisial untuk memfilter: ";
            char initial;
            cin >> initial;
            cout << "Kata-kata yang dimulai dengan '" << initial << "': ";
            filterNodes(root, initial);
            cout << endl;
            break;
        }
        case 6:
        {
            int totalNodes = countNodes(root);
            cout << "Total kata dalam tree: " << totalNodes << endl;
            break;
        }
        case 7:
        {
            infotype minValue = getMinValue(root);
            if (!minValue.word.empty()) {
                cout << "Nilai minimum dalam tree: " << minValue.word << endl;
            }
            break;
        }
        case 8:
        {
            infotype maxValue = getMaxValue(root);
            if (!maxValue.word.empty()) {
                cout << "Nilai maksimum dalam tree: " << maxValue.word << endl;
            }
            break;
        }
        case 9:
        {
            cout << "Kata yang sering dicari fitur belum diimplementasikan." << endl;
            break;
        }
        case 0:
        {
            cout << "Keluar dari program." << endl;
            break;
        }
        default:
        {
            cout << "Pilih menu yang valid." << endl;
            break;
        }
        }
    }
}
