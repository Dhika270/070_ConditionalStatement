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
}