#include <iostream>
#include <string>
#include <cmath> 
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
 
Node* SortedMerge(Node* a, Node* b) {
    Node* result = nullptr;
    if (a == nullptr) return b;
    else if (b == nullptr) return a;

    if (a->data.harga_awal <= b->data.harga_awal) {
        result = a;
        result->next = SortedMerge(a->next, b);
    } else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void MergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* cur = head;
    Node* tail = pivot;

    while (cur != pivot) {
        if (cur->data.harga_awal > pivot->data.harga_awal) { // Descending
            if (*newHead == nullptr) {
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev != nullptr) {
                prev->next = cur->next;
            }
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (*newHead == nullptr) {
        *newHead = pivot;
    }
    *newEnd = tail;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) {
        return head;
    }

    Node* newHead = nullptr;
    Node* newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

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

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(Node* head, float x) {
    Node* current = head;
    int n = 0;
    
    while (current != nullptr) {
        n++;
        current = current->next;
    }
    
    int fibMMm2 = 0; 
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 
    
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    
    int offset = -1;
    current = head;
    
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        
        Node* temp = head;
        for (int j = 0; j < i; j++) temp = temp->next;
        
        if (temp->data.harga_awal < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (temp->data.harga_awal > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }
    
    return -1;
}

int jumpSearch(Node* head, float x) {
    int n = 0;
    Node* current = head;
    
    while (current != nullptr) {
        n++;
        current = current->next;
    }
    
    int step = sqrt(n);
    int prev = 0;
    current = head;
    
    while (current != nullptr && current->data.harga_awal < x) {
        prev += step;
        for (int i = 0; i < step && current != nullptr; i++) {
            current = current->next;
        }
    }
    
    if (current == nullptr) return -1;
    
    Node* temp = head;
    for (int i = 0; i < prev; i++) {
        temp = temp->next;
    }
    
    while (temp != nullptr && temp->data.harga_awal < x) {
        temp = temp->next;
    }
    
    if (temp != nullptr && temp->data.harga_awal == x) return prev;
    
    return -1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(string str, int size, int badchar[256]) {
    int i;
    for (i = 0; i < 256; i++) badchar[i] = -1;
    for (i = 0; i < size; i++) badchar[(int)str[i]] = i;
}

int boyerMooreSearch(Node* head, string pattern) {
    int m = pattern.size();
    int badchar[256];
    
    badCharHeuristic(pattern, m, badchar);
    
    Node* current = head;
    int index = 0;
    
    while (current != nullptr) {
        string text = current->data.nama;
        int n = text.size();
        
        int s = 0;
        while (s <= (n - m)) {
            int j = m - 1;
            
            while (j >= 0 && pattern[j] == text[s + j]) j--;
            
            if (j < 0) {
                return index;
                s += (s + m < n) ? m - badchar[text[s + m]] : 1;
            } else {
                s += max(1, j - badchar[text[s + j]]);
            }
        }
        
        index++;
        current = current->next;
    }
    
    return -1;
}

int main() {
    int pilihan = 0;

    while (pilihan != 10) { 
        cout << "\nMenu Pendataan Barang Lelang:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Sort Barang (Ascending dengan Merge Sort)\n";
        cout << "6. Sort Barang (Descending dengan Quick Sort)\n";
        cout << "7. Cari Barang dengan Fibonacci Search (Harga Awal)\n";
        cout << "8. Cari Barang dengan Jump Search (Harga Awal)\n";
        cout << "9. Cari Barang dengan Boyer-Moore Search (Nama)\n";
        cout << "10. Keluar\n";
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
                MergeSort(&head);
                cout << "Data diurutkan secara ascending menggunakan Merge Sort.\n";
                tampil_barang(head);  
                break;
            case 6:
                quickSort(&head);
                cout << "Data diurutkan secara descending menggunakan Quick Sort.\n";
                tampil_barang(head);  
                break;
            case 7:
                {
                    float target;
                    cout << "Masukkan harga awal barang yang dicari: ";
                    cin >> target;
                    int result = fibonacciSearch(head, target);
                    if (result != -1)
                        cout << "Barang ditemukan di posisi: " << result + 1 << endl;
                    else
                        cout << "Barang tidak ditemukan." << endl;
                }
                break;
            case 8:
                {
                    float target;
                    cout << "Masukkan harga awal barang yang dicari: ";
                    cin >> target;
                    int result = jumpSearch(head, target);
                    if (result != -1)
                        cout << "Barang ditemukan di posisi: " << result + 1 << endl;
                    else
                        cout << "Barang tidak ditemukan." << endl;
                }
                break;
            case 9:
                {
                    string target;
                    cout << "Masukkan nama barang yang dicari: ";
                    cin.ignore();
                    getline(cin, target);
                    int result = boyerMooreSearch(head, target);
                    if (result != -1)
                        cout << "Barang ditemukan di posisi: " << result + 1 << endl;
                    else
                        cout << "Barang tidak ditemukan." << endl;
                }
                break;
            case 10:
                cout << "\nAnda keluar program\n" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid.\n" << endl;
        }
    }

    return 0;
}
