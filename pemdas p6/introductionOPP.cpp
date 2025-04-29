#include<iostream>
using namespace std;

class Mahasiswa{
public :
    int nim;
    string nama;
    float nilai;

    void printData(){
        cout << "nim :" << nim << endl;
        cout << "nama :" << nama << endl;
        cout << "nilai :" << nilai << endl;

    }
};

int main() {
    Mahasiswa mhs;
    mhs.nim = 2024;
    mhs.nama = "Dika";
    mhs.nilai = 90.5;

    mhs.printData();

}