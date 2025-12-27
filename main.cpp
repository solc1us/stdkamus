#include <iostream>
#include <cctype>
#include <string>
#include "tree.h"

using namespace std;

static void normalizeWord(string &s)
{
    if (s.empty())
        return;

    while (!s.empty() && isspace((unsigned char)s.front()))
        s.erase(s.begin());
    while (!s.empty() && isspace((unsigned char)s.back()))
        s.pop_back();
    if (s.empty())
        return;

    for (char &ch : s)
        ch = (char)tolower((unsigned char)ch);

    s[0] = (char)toupper((unsigned char)s[0]);
}

int main()
{
    adrNode root;
    createTree(root);

    infotype internalNodes[] = {{"A", ""}, {"B", ""}, {"C", ""}, {"D", ""}, {"E", ""}, {"F", ""}, {"G", ""}, {"H", ""}, {"I", ""}, {"J", ""}, {"K", ""}, {"L", ""}, {"M", ""}, {"N", ""}, {"O", ""}, {"P", ""}, {"Q", ""}, {"R", ""}, {"S", ""}, {"T", ""}, {"U", ""}, {"V", ""}, {"W", ""}, {"X", ""}, {"Y", ""}, {"Z", ""}};
    for (int i = 0; i < 26; i++)
    {
        adrNode newNode = createNode(internalNodes[i]);
        insertNode(root, newNode);
    }

    infotype words[] = {
        {"Apple", "Buah apel; buah berwarna merah/hijau yang rasanya manis atau asam."},
        {"Zebra", "Hewan mamalia bergaris hitam-putih yang hidup di Afrika."},
        {"Banana", "Buah pisang; buah kuning yang kaya kalium."},
        {"Cherry", "Buah ceri; buah kecil bulat, biasanya merah dan manis."},
        {"Date", "Buah kurma; buah manis dari pohon kurma."},
        {"Fig", "Buah ara; buah lembut dengan biji kecil-kecil."},
        {"Sour", "Rasa asam; kebalikan dari manis."},
        {"Raspberry", "Buah beri berwarna merah/ungu, rasanya manis-asam."},
        {"Lemon", "Buah lemon; buah kuning dengan rasa sangat asam."},
        {"Mango", "Buah mangga; buah tropis manis, dagingnya kuning/oranye."},
        {"Nectarine", "Buah nektarin; mirip peach tapi kulitnya halus."},
        {"Computer", "Alat elektronik untuk memproses data dan menjalankan program."},
        {"Building", "Struktur yang dibangun untuk tempat tinggal atau kerja."},
        {"Mountain", "Puncak tanah yang tinggi dan curam."},
        {"Ocean", "Tubuh air asin yang sangat luas di permukaan Bumi."},
        {"Car", "Kendaraan bermotor dengan empat roda untuk transportasi."},
        {"Table", "Furnitur dengan permukaan datar untuk meletakkan barang."},
        {"Clock", "Alat untuk menunjukkan waktu."},
        {"Camera", "Alat untuk mengambil foto atau video."},
        {"Guitar", "Alat musik berdawai yang dimainkan dengan tangan."},
        {"Window", "Bukaan dinding yang memungkinkan cahaya masuk."},
        {"Bridge", "Struktur yang menghubungkan dua tempat terpisah."},
        {"Telescope", "Alat optik untuk melihat benda-benda jauh di langit."}};

    int nWords = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < nWords; i++)
    {
        normalizeWord(words[i].word);
        adrNode newNode = createNode(words[i]);
        insertNode(root, newNode);
    }

    int choice = -1;
    while (choice != 0)
    {

        displayMenu();

        cout << "Pilih menu: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        
        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
        {
            cout << "Masukkan kata: ";
            infotype info;
            getline(cin, info.word);
            normalizeWord(info.word);
            cout << "Masukkan arti: ";
            getline(cin, info.meaning);
            info.searchCount = 0;

            adrNode newNode = createNode(info);

            insertNode(root, newNode);
            break;
        }

        case 2:
        {
            cout << "Masukkan kata yang ingin dicari: ";
            infotype searchValue;
            getline(cin, searchValue.word);
            normalizeWord(searchValue.word);

            adrNode foundNode = searchNode(root, searchValue);
            if (foundNode != nullptr)
            {
                if (foundNode->info.word.size() == 1 &&
                    foundNode->info.word[0] >= 'A' &&
                    foundNode->info.word[0] <= 'Z')
                {
                    cout << "Itu hanya header huruf." << endl;
                }
                else
                {
                    foundNode->info.searchCount++;
                    cout << "Kata : " << foundNode->info.word << endl;
                    cout << "Arti : " << foundNode->info.meaning << endl;
                    cout << "Dicari sebanyak: "
                         << foundNode->info.searchCount << "x" << endl;
                }
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
            infotype deleteValue;
            cin >> deleteValue.word;
            normalizeWord(deleteValue.word);
            deleteValue.meaning = "";
            deleteNode(root, deleteValue);
            cout << "Kata " << deleteValue.word << " telah dihapus." << endl;
            break;
        }

        case 5:
        {
            cout << "Masukkan inisial untuk memfilter: ";
            char initial;
            cin >> initial;
            initial = (char)toupper((unsigned char)initial);
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
            if (!minValue.word.empty())
            {
                cout << "Kata dengan abjad paling awal dalam tree: " << minValue.word << endl;
            }
            break;
        }
        case 8:
        {
            infotype maxValue = getMaxValue(root);
            if (!maxValue.word.empty())
            {
                cout << "Kata dengan abjad paling akhir dalam tree: " << maxValue.word << endl;
            }
            break;
        }
        case 9:
        {
            displayMostSearched(root);
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
