#include <iostream>
using namespace std;

float Panjang, Lebar;

float FungsiHitungLuas(){
    return Panjang * Lebar;
}
int main()
{
    cout << "masukkan panjangnya : ";
    cin >> Panjang;
    cout << "masukkan lebarnya : ";
    cin >> Lebar;

    cout << "Luas Persegi Panjang : " << FungsiHitungLuas();
}   