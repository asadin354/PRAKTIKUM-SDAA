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

// Stack implementation (LIFO)
struct Stack {
    Node* top = nullptr;

    // Push to Stack
    void push(barang_lelang barang) {
        Node* newNode = new Node;
        newNode->data = barang;
        newNode->next = top;
        top = newNode;
        cout << "\nBarang berhasil ditambahkan ke Stack!\n" << endl;
    }

    // Pop from Stack
    void pop() {
        if (top == nullptr) {
            cout << "\nStack kosong, tidak ada barang yang bisa di-pop.\n" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "\nBarang berhasil di-pop dari Stack!\n" << endl;
    }

    // Tampilkan Stack secara lengkap
    void tampilStack() {
        if (top == nullptr) {
            cout << "\nStack kosong.\n" << endl;
            return;
        }
        Node* current = top;
        int i = 1;
        cout << "\nDaftar Barang di Stack:\n";
        cout << "----------------------------------\n";
        while (current != nullptr) {
            cout << i << ". Nama: " << current->data.nama << endl;
            cout << "   Harga Awal: " << current->data.harga_awal << endl;
            cout << "   Deskripsi: " << current->data.deskripsi << endl;
            cout << "   Tanggal Awal Lelang: " << current->data.tanggal_awal << endl;
            cout << "   Tanggal Berakhir Lelang: " << current->data.tanggal_berakhir << endl;
            cout << "----------------------------------\n";
            current = current->next;
            i++;
        }
    }
};

// Queue implementation (FIFO)
struct Queue {
    Node* front = nullptr;
    Node* rear = nullptr;

    // Enqueue (tambahkan ke belakang Queue)
    void enqueue(barang_lelang barang) {
        Node* newNode = new Node;
        newNode->data = barang;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "\nBarang berhasil ditambahkan ke Queue!\n" << endl;
    }

    // Dequeue (hapus dari depan Queue)
    void dequeue() {
        if (front == nullptr) {
            cout << "\nQueue kosong, tidak ada barang yang bisa di-dequeue.\n" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        cout << "\nBarang berhasil di-dequeue dari Queue!\n" << endl;
    }

    // Tampilkan Queue secara lengkap
    void tampilQueue() {
        if (front == nullptr) {
            cout << "\nQueue kosong.\n" << endl;
            return;
        }
        Node* current = front;
        int i = 1;
        cout << "\nDaftar Barang di Queue:\n";
        cout << "----------------------------------\n";
        while (current != nullptr) {
            cout << i << ". Nama: " << current->data.nama << endl;
            cout << "   Harga Awal: " << current->data.harga_awal << endl;
            cout << "   Deskripsi: " << current->data.deskripsi << endl;
            cout << "   Tanggal Awal Lelang: " << current->data.tanggal_awal << endl;
            cout << "   Tanggal Berakhir Lelang: " << current->data.tanggal_berakhir << endl;
            cout << "----------------------------------\n";
            current = current->next;
            i++;
        }
    }
};

// Fungsi tambah barang yang dapat digunakan oleh Stack dan Queue
barang_lelang buat_barang() {
    barang_lelang barang;
    cout << "\nMasukkan nama barang: ";
    cin.ignore();
    getline(cin, barang.nama);
    cout << "Masukkan harga awal barang: ";
    cin >> barang.harga_awal;
    cout << "Masukkan deskripsi barang: ";
    cin.ignore();
    getline(cin, barang.deskripsi);
    cout << "Masukkan tanggal awal lelang (contoh: 21-10-2024): ";
    getline(cin, barang.tanggal_awal);
    cout << "Masukkan tanggal berakhir lelang (contoh: 25-10-2024): ";
    getline(cin, barang.tanggal_berakhir);
    return barang;
}

int main() {
    Stack stack;
    Queue queue;
    int pilihan = 0;

    while (pilihan != 7) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Barang ke Stack\n";
        cout << "2. Pop Barang dari Stack\n";
        cout << "3. Tampilkan Barang di Stack\n";
        cout << "4. Tambah Barang ke Queue\n";
        cout << "5. Dequeue Barang dari Queue\n";
        cout << "6. Tampilkan Barang di Queue\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                barang_lelang barang = buat_barang();
                stack.push(barang);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                stack.tampilStack();
                break;
            case 4: {
                barang_lelang barang = buat_barang();
                queue.enqueue(barang);
                break;
            }
            case 5:
                queue.dequeue();
                break;
            case 6:
                queue.tampilQueue();
                break;
            case 7:
                cout << "\nAnda keluar dari program\n" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid.\n" << endl;
        }
    }

    return 0;
}
