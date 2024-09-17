#include <iostream>
using namespace std;

void pindahkanMenara(int jumlahPiringan, char MenaraAsal, char MenaraTujuan, char MenaraSementara) {
    if (jumlahPiringan == 1) {
        cout << "Pindahkan piringan " << jumlahPiringan << " dari " << MenaraAsal << " ke " << MenaraTujuan << endl;
    } else {
        pindahkanMenara(jumlahPiringan - 1, MenaraAsal, MenaraSementara, MenaraTujuan);
        cout << "Pindahkan piringan " << jumlahPiringan << " dari " << MenaraAsal << " ke " << MenaraTujuan << endl;
        pindahkanMenara(jumlahPiringan - 1, MenaraSementara, MenaraTujuan, MenaraAsal);
    }
}

int main() {
    int jumlahPiringan;
    cout << "Masukkan jumlah piringan: ";
    cin >> jumlahPiringan;

    cout << "\nLangkah Langkahnya Adalah Sebagai Berikut: ";
    pindahkanMenara(jumlahPiringan, 'A', 'C', 'B');
    cout << "\nKeterangan : \n A = Menara Asal \n B = Menara Sementara \n C = Menara Tujuan";
    return 0;
}
