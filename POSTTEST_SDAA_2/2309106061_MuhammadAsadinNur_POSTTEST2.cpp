#include <iostream>
#include <string>
using namespace std;

struct barang_lelang {
    string nama;
    float harga_awal;
    string deskripsi;
    string tanggal_awal;
    string tanggal_berakhir;
};

void tambah_barang(barang_lelang barang[], int &jumlah_barang) {
    cout << "\nMasukkan nama barang: ";
    cin.ignore();
    getline(cin, barang[jumlah_barang].nama);
    cout << "Masukkan harga awal barang: ";
    cin >> barang[jumlah_barang].harga_awal;
    cout << "Masukkan deskripsi barang: ";
    cin.ignore();
    getline(cin, barang[jumlah_barang].deskripsi);
    cout << "Masukkan tanggal awal lelang (contoh: 21-10-2024): ";
    getline(cin, barang[jumlah_barang].tanggal_awal);
    cout << "Masukkan tanggal berakhir lelang (contoh: 25-10-2024): ";
    getline(cin, barang[jumlah_barang].tanggal_berakhir);
    jumlah_barang++;
    cout << "\nBarang berhasil ditambahkan!\n" << endl;
}

void tampil_barang(const barang_lelang barang[], int jumlah_barang) {
    cout << "\nDaftar Barang Lelang:" << endl;
    cout << "----------------------------------:" << endl;
    if (jumlah_barang == 0) {
        cout << "\nTidak ada barang yang tersedia untuk ditampilkan.\n" << endl;
        return;
    }
    for (int i = 0; i < jumlah_barang; i++) {
        cout << i + 1 << ". " << endl;
        cout << "Nama: " << barang[i].nama << endl;
        cout << "Harga Awal: " << barang[i].harga_awal << endl;
        cout << "Deskripsi: " << barang[i].deskripsi << endl;
        cout << "Tanggal Awal Lelang: " << barang[i].tanggal_awal << endl;
        cout << "Tanggal Berakhir Lelang: " << barang[i].tanggal_berakhir << endl;
        cout << "-----------------------------" << endl;
    }
}

void tampil_nama_barang(const barang_lelang barang[], int jumlah_barang) {
    cout << "\nDaftar Barang Lelang:\n" << endl;
    for (int i = 0; i < jumlah_barang; i++) {
        cout << i + 1 << ". " << barang[i].nama << endl;
    }
}

void update_barang(barang_lelang barang[], int jumlah_barang) {
    if (jumlah_barang == 0) {
        cout << "\nTidak ada barang yang tersedia untuk diupdate.\n" << endl;
        return;
    }
    
    tampil_nama_barang(barang, jumlah_barang);
    
    int pilihan;
    cout << "\nMasukkan nomor barang yang ingin diupdate: ";
    cin >> pilihan;
    pilihan--; 

    if (pilihan >= 0 && pilihan < jumlah_barang) {
        cout << "Masukkan nama barang baru: ";
        cin.ignore();
        getline(cin, barang[pilihan].nama);
        cout << "Masukkan harga awal barang baru: ";
        cin >> barang[pilihan].harga_awal;
        cout << "Masukkan deskripsi barang baru: ";
        cin.ignore();
        getline(cin, barang[pilihan].deskripsi);
        cout << "Masukkan tanggal awal lelang baru (contoh: 21-10-2024): ";
        getline(cin, barang[pilihan].tanggal_awal);
        cout << "Masukkan tanggal berakhir lelang baru (contoh: 25-10-2024): ";
        getline(cin, barang[pilihan].tanggal_berakhir);
        cout << "\nBarang berhasil diperbarui!\n" << endl;
    } else {
        cout << "\nPilihan tidak valid.\n" << endl;
    }
}

void hapus_barang(barang_lelang barang[], int &jumlah_barang) {
    if (jumlah_barang == 0) {
        cout << "\nTidak ada barang yang tersedia untuk dihapus.\n" << endl;
        return;
    }
    
    tampil_nama_barang(barang, jumlah_barang);  
    
    int pilihan;
    cout << "\nMasukkan nomor barang yang ingin dihapus: ";
    cin >> pilihan;
    pilihan--;  

    if (pilihan >= 0 && pilihan < jumlah_barang) {
        for (int i = pilihan; i < jumlah_barang - 1; i++) {
            barang[i] = barang[i + 1];  
        }
        jumlah_barang--;
        cout << "\nBarang berhasil dihapus\n" << endl;
    } else {
        cout << "\nPilihan tidak valid.\n" << endl;
    }
}

int main() {
    const int MAX_BARANG = 100;
    barang_lelang barang[MAX_BARANG];
    int jumlah_barang = 0;
    int pilihan = 0;

    while (pilihan != 5) {
        cout << "\nMenu Pendataan Barang Lelang:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambah_barang(barang, jumlah_barang);
                break;
            case 2:
                tampil_barang(barang, jumlah_barang);
                break;
            case 3:
                update_barang(barang, jumlah_barang);
                break;
            case 4:
                hapus_barang(barang, jumlah_barang);
                break;
            case 5:
                cout << "\nAnda keluar program\n" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid.\n" << endl;
        }
    }

    return 0;
}
