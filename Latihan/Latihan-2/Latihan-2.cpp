#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

typedef struct Tnode {
    string data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head, *tail;

int pil, menu;
char pilihan[1];

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main() {
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "=======================================" << endl;
    cout << "Silahkan pilihan program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    cout << "\n----------------------------------------\n";
    
    if (menu == 1 || menu == 2) {
        do {
            if (menu == 1) {
                cout << "Double Linked List Non Circular (DLLNC) (head)" << endl;
            } else {
                cout << "Double Linked List Non Circular (DLLNC) (head dan Tail)" << endl;
            }
            cout << "==============================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang (Ke-N)" << endl;
            cout << "6. Hapus Target" << endl;
            cout << "7. Reset (Clear)" << endl;
            cout << "8. Kembali Ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil) {
                case 1: 
                    if (menu == 1) tambahDepanH(); 
                    else tambahDepanHT(); 
                    break;
                case 2: 
                    if (menu == 1) tambahBelakangH(); 
                    else tambahBelakangHT(); 
                    break;
                case 3: 
                    if (menu == 1) tampilkanH(); 
                    else tampilkanHT(); 
                    break;
                case 4: 
                    if (menu == 1) hapusDepanH(); 
                    else hapusDepanHT(); 
                    break;
                case 5: 
                    if (menu == 1) hapusBelakangH(); 
                    else hapusBelakangHT(); 
                    break;
                case 6: 
                    if (menu == 1) hapusTargetH(); 
                    else hapusTargetHT(); 
                    break;
                case 7: 
                    if (menu == 1) clearH(); 
                    else clearHT(); 
                    break;
                case 8: 
                    cout << "\n"; 
                    goto menu;
                default: 
                    cout << "\n"; 
                    goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            cout << "\n==============================================\n";
        } while (pil < 8);
    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Ahmad Riyadhi (2510817110004)" << endl;
    }
    return 0;
}

void initH() { 
    head = NULL; 
}

void initHT() { 
    head = NULL; 
    tail = NULL; 
}

int isEmptyH() { 
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isEmptyHT() { 
    if (tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void tambahDepanH() {
    cout << "Masukan Data (pisahkan spasi): ";
    string input, word; 
    cin >> ws; 
    getline(cin, input);
    stringstream ss(input);
    Tnode *tempHead = NULL;
    Tnode *tempTail = NULL;
    
    while (ss >> word) {
        Tnode *baru = new Tnode;
        baru->data = word; 
        baru->next = NULL;
        baru->prev = NULL;
        
        if (!tempHead) { 
            tempHead = baru;
            tempTail = baru; 
        } else { 
            tempTail->next = baru; 
            baru->prev = tempTail; 
            tempTail = baru; 
        }
    }
    
    if (isEmptyH() == 1) { 
        head = tempHead; 
    } else { 
        tempTail->next = head; 
        head->prev = tempTail; 
        head = tempHead; 
    }
    cout << "Data berhasil dimasukkan di bagian depan.";
}

void tambahBelakangH() {
    cout << "Masukan Data (pisahkan spasi): ";
    string input, word; 
    cin >> ws; 
    getline(cin, input);
    stringstream ss(input);
    Tnode *tempHead = NULL;
    Tnode *tempTail = NULL;
    
    while (ss >> word) {
        Tnode *baru = new Tnode;
        baru->data = word; 
        baru->next = NULL;
        baru->prev = NULL;
        
        if (!tempHead) { 
            tempHead = baru;
            tempTail = baru; 
        } else { 
            tempTail->next = baru; 
            baru->prev = tempTail; 
            tempTail = baru; 
        }
    }
    
    if (isEmptyH() == 1) { 
        head = tempHead; 
    } else {
        Tnode *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = tempHead; 
        tempHead->prev = bantu;
    }
    cout << "Data berhasil dimasukkan di bagian belakang.";
}

void hapusTargetH() {
    cout << "Masukkan data target untuk dihapus: ";
    string target; 
    cin >> target;
    Tnode *bantu = head; 
    bool found = false;
    
    while (bantu != NULL) {
        if (bantu->data == target) {
            found = true; 
            Tnode *hapus = bantu;
            
            if (bantu == head) {
                head = head->next; 
                if (head != NULL) {
                    head->prev = NULL;
                }
                bantu = head;
            } else {
                bantu->prev->next = bantu->next;
                if (bantu->next != NULL) {
                    bantu->next->prev = bantu->prev;
                }
                bantu = bantu->next;
            }
            delete hapus;
        } else {
            bantu = bantu->next;
        }
    }
    
    if (found) {
        cout << "Semua data target \"" << target << "\" berhasil dihapus.\n";
    } else {
        cout << "Target tidak ditemukan dalam list.\n";
    }
}

void hapusBelakangH() {
    if (isEmptyH()) { 
        cout << "Tidak ada data pada Linked List\n"; 
        return; 
    }
    int n, count = 0;
    cout << "Hapus node ke-N dari belakang. Masukkan N: "; 
    cin >> n;
    
    Tnode *curr = head;
    Tnode *tailTemp = NULL;
    
    while (curr != NULL) { 
        count++; 
        tailTemp = curr; 
        curr = curr->next; 
    }
    
    int targetPos;
    if (n % count == 0) {
        targetPos = count;
    } else {
        targetPos = n % count;
    }
    
    curr = tailTemp;
    for (int i = 1; i < targetPos; i++) {
        curr = curr->prev;
    }
    
    string data = curr->data;
    if (curr == head && count == 1) { 
        head = NULL; 
    } else if (curr == head) { 
        head = head->next; 
        head->prev = NULL; 
    } else if (curr == tailTemp) { 
        curr->prev->next = NULL; 
    } else { 
        curr->prev->next = curr->next; 
        curr->next->prev = curr->prev; 
    }
    
    delete curr;
    cout << "Data \"" << data << "\" berhasil dihapus." << endl;
}

void clearH() {
    int urutan = 1;
    while (head != NULL) {
        Tnode *hapus;
        if (urutan % 2 != 0) { 
            hapus = head; 
            head = head->next; 
            if (head != NULL) {
                head->prev = NULL; 
            }
        } else { 
            hapus = head;
            while (hapus->next != NULL) {
                hapus = hapus->next;
            }
            hapus->prev->next = NULL;
        }
        cout << "Data terhapus: " << hapus->data << " (Urutan: " << urutan << ")\n";
        delete hapus; 
        urutan++;
    }
    initH(); 
    cout << "Seluruh data dibersihkan secara bergantian.\n";
}

void tampilkanH() {
    Tnode *bantu = head;
    if (isEmptyH() == 0) {
        while (bantu != NULL) { 
            cout << bantu->data << ' '; 
            bantu = bantu->next; 
        }
        cout << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List";
    }
}

void hapusDepanH() {
    if (isEmptyH() == 0) {
        Tnode *hapus = head; 
        string data = hapus->data;
        if (head->next != NULL) { 
            head = head->next; 
            head->prev = NULL; 
        } else { 
            initH(); 
        }
        delete hapus; 
        cout << "Data \"" << data << "\" berhasil dihapus dari bagian depan." << endl;
    } else {
        cout << "Tidak ada data pada Linked List" << endl;
    }
}

void tambahDepanHT() {
    cout << "Masukan Data (pisahkan spasi): ";
    string input, word; 
    cin >> ws; 
    getline(cin, input);
    stringstream ss(input);
    Tnode *tempHead = NULL;
    Tnode *tempTail = NULL;
    
    while (ss >> word) {
        Tnode *baru = new Tnode;
        baru->data = word; 
        baru->next = NULL;
        baru->prev = NULL;
        
        if (!tempHead) { 
            tempHead = baru;
            tempTail = baru; 
        } else { 
            tempTail->next = baru; 
            baru->prev = tempTail; 
            tempTail = baru; 
        }
    }
    
    if (isEmptyHT() == 1) { 
        head = tempHead; 
        tail = tempTail; 
    } else { 
        tempTail->next = head; 
        head->prev = tempTail; 
        head = tempHead; 
    }
    cout << "Data berhasil dimasukan di bagian depan.";
}

void tambahBelakangHT() {
    cout << "Masukan Data (pisahkan spasi): ";
    string input, word; 
    cin >> ws; 
    getline(cin, input);
    stringstream ss(input);
    Tnode *tempHead = NULL;
    Tnode *tempTail = NULL;
    
    while (ss >> word) {
        Tnode *baru = new Tnode;
        baru->data = word; 
        baru->next = NULL;
        baru->prev = NULL;
        
        if (!tempHead) { 
            tempHead = baru;
            tempTail = baru; 
        } else { 
            tempTail->next = baru; 
            baru->prev = tempTail; 
            tempTail = baru; 
        }
    }
    
    if (isEmptyHT() == 1) { 
        head = tempHead; 
        tail = tempTail; 
    } else { 
        tail->next = tempHead; 
        tempHead->prev = tail; 
        tail = tempTail; 
    }
    cout << "Data berhasil dimasukan di bagian belakang.";
}

void hapusTargetHT() {
    cout << "Masukkan data target untuk dihapus: ";
    string target; 
    cin >> target;
    Tnode *bantu = head; 
    bool found = false;
    
    while (bantu != NULL) {
        if (bantu->data == target) {
            found = true; 
            Tnode *hapus = bantu;
            
            if (bantu == head) {
                head = head->next; 
                if (head != NULL) {
                    head->prev = NULL; 
                } else {
                    tail = NULL;
                }
                bantu = head;
            } else if (bantu == tail) {
                tail = tail->prev; 
                tail->next = NULL;
                bantu = NULL;
            } else {
                bantu->prev->next = bantu->next;
                bantu->next->prev = bantu->prev;
                bantu = bantu->next;
            }
            delete hapus;
        } else {
            bantu = bantu->next;
        }
    }
    
    if (found) {
        cout << "Semua data target \"" << target << "\" berhasil dihapus.\n";
    } else {
        cout << "Target tidak ditemukan dalam list.\n";
    }
}

void hapusBelakangHT() {
    if (isEmptyHT()) { 
        cout << "Tidak ada data pada Linked List\n"; 
        return; 
    }
    int n, count = 0;
    cout << "Hapus node ke-N dari belakang. Masukkan N: "; 
    cin >> n;
    
    Tnode *curr = head;
    while (curr != NULL) { 
        count++; 
        curr = curr->next; 
    }
    
    int targetPos;
    if (n % count == 0) {
        targetPos = count;
    } else {
        targetPos = n % count;
    }
    
    curr = tail;
    for (int i = 1; i < targetPos; i++) {
        curr = curr->prev;
    }
    
    string data = curr->data;
    if (curr == head && curr == tail) { 
        head = NULL;
        tail = NULL; 
    } else if (curr == head) { 
        head = head->next; 
        head->prev = NULL; 
    } else if (curr == tail) { 
        tail = tail->prev; 
        tail->next = NULL; 
    } else { 
        curr->prev->next = curr->next; 
        curr->next->prev = curr->prev; 
    }
    
    delete curr;
    cout << "Data \"" << data << "\" berhasil dihapus." << endl;
}

void clearHT() {
    int urutan = 1;
    while (head != NULL) {
        Tnode *hapus;
        if (urutan % 2 != 0) {
            hapus = head; 
            head = head->next;
            if (head != NULL) {
                head->prev = NULL; 
            } else {
                tail = NULL;
            }
        } else {
            hapus = tail; 
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL; 
            } else {
                head = NULL;
            }
        }
        cout << "Data terhapus: " << hapus->data << " (Urutan: " << urutan << ")\n";
        delete hapus; 
        urutan++;
    }
    initHT(); 
    cout << "Seluruh data dibersihkan secara bergantian.\n";
}

void tampilkanHT() {
    Tnode *bantu = head;
    if (isEmptyHT() == 0) {
        while (bantu != NULL) { 
            cout << bantu->data << ' '; 
            bantu = bantu->next; 
        }
        cout << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List";
    }
}

void hapusDepanHT() {
    if (isEmptyHT() == 0) {
        Tnode *hapus = head; 
        string data = hapus->data;
        if (head->next != NULL) { 
            head = head->next; 
            head->prev = NULL; 
        } else { 
            initHT(); 
        }
        delete hapus; 
        cout << "Data \"" << data << "\" berhasil dihapus dari bagian depan." << endl;
    } else {
        cout << "Tidak ada data pada Linked List" << endl;
    }
}