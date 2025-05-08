//070_singLeLinkedlist
#include <iostream>
using namespace std;

class Node
{
    public:
        int noMhs;
        Node *next;

};

class LinkedList
{
    Node *START;

    public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa:";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if((START != NULL ) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *Previous = START;
        Node *current = START;
        while ((current != NULL) && (nim >= current ->noMhs))
        {
            if(nim == current ->noMhs)
            {
            cout << "\nDuplikasi noMhs tidak diijinkan\n";
            return; 
            }
            Previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        Previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node **Previous, Node ** current)
    {
        *Previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)-> noMhs))
        {
            *Previous = *current;
            *current = (*current)->next;
        }

        return (*current !=NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, previous, current))
            return false;

        if (current == START)
        {
            START = START->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        return true;
    }

    void traverse()
    {
        if (!listEmpty())
        {
            Node *currentNode = START;
            cout << "\nData dalam list adalah:\n";
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
        else
        {
            cout << "\nList Kosong\n";
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data dalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan (1-5): ";
        cin >> ch;
    }

        switch (ch)
        {
        case '1':
            mhs.addNode();
            break;
        }

        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n" << endl;
                break;
            }
            
            cout << "\nMasukkan nomor mahasiswa yang akan dihapus : ";
            cin >> nim;
            if (mhs.delNode(nim) == false)
                cout << "Data tidak ditemukan" << endl;
            else
                cout << "Data dengan nomor mahasiswa " << nim << " berhasil dihapus" << endl;
            break;

        case '3':
            mhs.traverse();
            break;

        case '4':
            if (mhs.listEmpty() == true)
            {
                cout << "\nList Kosong\n";
                break;
            }