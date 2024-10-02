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

struct Node {
    barang_lelang data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void tambah_barang(Node* &head, Node* &tail) {
    Node* newNode = new Node;
    cout << "\nMasukkan nama barang: ";
    cin.ignore();
    getline(cin, newNode->data.nama);
    cout << "Masukkan harga awal barang: ";
    cin >> newNode->data.harga_awal;
    cout << "Masukkan deskripsi barang: ";
    cin.ignore();
    getline(cin, newNode->data.deskripsi);
    cout << "Masukkan tanggal awal lelang (contoh: 21-10-2024): ";
    getline(cin, newNode->data.tanggal_awal);
    cout << "Masukkan tanggal berakhir lelang (contoh: 25-10-2024): ";
    getline(cin, newNode->data.tanggal_berakhir);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    
    cout << "\nBarang berhasil ditambahkan!\n" << endl;
}

void tampil_barang(Node* head) {
    cout << "\nDaftar Barang Lelang:" << endl;
    cout << "----------------------------------:" << endl;
    if (head == nullptr) {
        cout << "\nTidak ada barang yang tersedia untuk ditampilkan.\n" << endl;
        return;
    }
    Node* current = head;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". " << endl;
        cout << "Nama: " << current->data.nama << endl;
        cout << "Harga Awal: " << current->data.harga_awal << endl;
        cout << "Deskripsi: " << current->data.deskripsi << endl;
        cout << "Tanggal Awal Lelang: " << current->data.tanggal_awal << endl;
        cout << "Tanggal Berakhir Lelang: " << current->data.tanggal_berakhir << endl;
        cout << "-----------------------------" << endl;
        current = current->next;
        i++;
    }
}

void update_barang(Node* head) {
    if (head == nullptr) {
        cout << "\nTidak ada barang yang tersedia untuk diupdate.\n" << endl;
        return;
    }

    tampil_barang(head);

    int pilihan;
    cout << "\nMasukkan nomor barang yang ingin diupdate: ";
    cin >> pilihan;
    cin.ignore(); 

    Node* current = head;
    int index = 1;
    while (current != nullptr && index < pilihan) {
        current = current->next;
        index++;
    }

    if (current != nullptr) {
        cout << "Masukkan nama barang baru: ";
        getline(cin, current->data.nama);
        cout << "Masukkan harga awal barang baru: ";
        cin >> current->data.harga_awal;
        cout << "Masukkan deskripsi barang baru: ";
        cin.ignore();
        getline(cin, current->data.deskripsi);
        cout << "Masukkan tanggal awal lelang baru (contoh: 21-10-2024): ";
        getline(cin, current->data.tanggal_awal);
        cout << "Masukkan tanggal berakhir lelang baru (contoh: 25-10-2024): ";
        getline(cin, current->data.tanggal_berakhir);
        cout << "\nBarang berhasil diperbarui!\n" << endl;
    } else {
        cout << "\nPilihan tidak valid.\n" << endl;
    }
}

void hapus_barang(Node* &head) {
    if (head == nullptr) {
        cout << "\nTidak ada barang yang tersedia untuk dihapus.\n" << endl;
        return;
    }

    tampil_barang(head);

    int pilihan;
    cout << "\nMasukkan nomor barang yang ingin dihapus: ";
    cin >> pilihan;
    cin.ignore(); 

    if (pilihan == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "\nBarang berhasil dihapus\n" << endl;
    } else {
        Node* current = head;
        int index = 1;
        while (current != nullptr && index < pilihan - 1) {
            current = current->next;
            index++;
        }
        if (current != nullptr && current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "\nBarang berhasil dihapus\n" << endl;
        } else {
            cout << "\nPilihan tidak valid.\n" << endl;
        }
    }
}

void hapus_semua_barang(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
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
                tambah_barang(head, tail);
                break;
            case 2:
                tampil_barang(head);
                break;
            case 3:
                update_barang(head);
                break;
            case 4:
                hapus_barang(head);
                break;
            case 5:
                hapus_semua_barang(head);
                cout << "\nAnda keluar program\n" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid.\n" << endl;
        }
    }

    return 0;
}
