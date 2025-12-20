#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    adrNode root;
    createTree(root);

    string words[] = {"Apple", "Zebra", "Banana", "Cherry", "Date", "Fig", "Sour", "Raspberry", "Lemon", "Mango", "Nectarine"};
    for (int i = 0; i < 10; i++) {
        adrNode newNode = createNode(words[i]);
        insertNode(root, newNode);
    }

    int choice;
    while (choice != 9)
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
            cin >> info;
            adrNode newNode = createNode(info);
            insertNode(root, newNode);
            break;
            cout << endl
                 << "Masukkan kata yang ingin dicari: ";
            infotype searchValue;
            cin >> searchValue;
            adrNode foundNode = searchNode(root, searchValue);
            if (foundNode != nullptr)
            {
                cout << "Kata " << searchValue << " ditemukan." << endl;
            }
            else
            {
                cout << "Kata " << searchValue << " tidak ditemukan." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Ascending order / Descending order?" << endl;
            cout << "1. Ascending" << endl;
            cout << "2. Descending" << endl;
            int orderChoice;
            cin >> orderChoice;
            if (orderChoice == 1)
            {
                cout << "Tree dalam urutan menaik: ";
                displayTreeAscending(root);
                cout << endl;
            }
            else if (orderChoice == 2)
            {
            }
            else
            {
                cout << "Pilihan tidak valid. Menampilkan dalam urutan menurun secara default: ";
                displayTreeAscending(root);
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Masukkan kata yang ingin dihapus: ";
            infotype deleteValue;
            cin >> deleteValue;
            deleteNode(root, deleteValue);
            cout << "Kata " << deleteValue << " telah dihapus (jika ada)." << endl;
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
            cout << "Total node dalam tree: " << totalNodes << endl;
            break;
        }
        case 7:
        {
            infotype minValue = getMinValue(root);
            if (!minValue.empty()) {
                cout << "Nilai minimum dalam tree: " << minValue << endl;
            }
            break;
        }
        case 8:
        {
            infotype maxValue = getMaxValue(root);
            if (!maxValue.empty()) {
                cout << "Nilai maksimum dalam tree: " << maxValue << endl;
            }
            break;
        }
        case 9:
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
