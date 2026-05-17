#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
};

TNode *head;
TNode *tail;

int pil;
char pilihan[2];
string dataBaru;
string dataDelete;

void init();
int isEmpty();
int hitungNode();
void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main() {
    do {
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "==================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan : ";
        
        cin >> pilihan;
        pil = atoi(pilihan);

        switch(pil) {
            case 1: tambahDepan(); break;
            case 2: tambahBelakang(); break;
            case 3: hapusDepan(); break;
            case 4: hapusBelakang(); break;
            case 5: tampilkan(); break;
            case 6: reset(); break;
            case 7: cariData(); break;
            case 8: hapusData(); break;
            case 9: sisipkanSebelum(); break;
            case 10: sisipkanSetelah(); break;
            case 11:
                cout << "\nTERIMA KASIH" << endl;
                cout << "Program was made by Ahmad Riyadhi (2510817110004)." << endl;
                break;
            default: cout << "Pilihan tidak valid!" << endl; break;
        }

        if(pil != 11) {
            cout << "\nPress any key to continue!" << endl;
            getch();
            system("cls");
        }
    } while (pil != 11);
    return 0;
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

int hitungNode() {
    if(isEmpty() == 1) return 0;
    int count = 0;
    TNode* bantu = head;
    do {
        count++;
        bantu = bantu->next;
    } while(bantu != head);
    return count;
}

void tambahDepan() {
    cout << "Masukkan data (space untuk misah data) : ";
    string inputLine;
    cin.ignore(256, '\n');
    getline(cin, inputLine);

    stringstream ss(inputLine);
    string word;
    vector<string> words;

    while(ss >> word) {
        words.push_back(word);
    }

    for(int i = words.size() - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = words[i];
        baru->next = baru;

        if(isEmpty() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    TNode *baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan dibagian belakang." << endl;
}

void hapusDepan() {
    if(isEmpty() == 0) {
        int n;
        cout << "Masukkan nilai N (Hapus node ke-N dari depan) : ";
        cin >> n;
        int total = hitungNode();
        
        if(n >= total) {
            TNode *hapus = tail;
            dataDelete = hapus->data;
            if(head != tail) {
                TNode *newTail = head;
                while(newTail->next != tail) {
                    newTail = newTail->next;
                }
                tail = newTail;
                tail->next = head;
            } else {
                init();
            }
            delete hapus;
        } 
        else if(n <= 1) {
            TNode *hapus = head;
            dataDelete = hapus->data;
            if(head != tail) {
                head = head->next;
                tail->next = head;
            } else {
                init();
            }
            delete hapus;
        } 
        else {
            TNode *bantu = head;
            for(int i = 1; i < n - 1; i++) {
                bantu = bantu->next;
            }
            TNode *hapus = bantu->next;
            dataDelete = hapus->data;
            bantu->next = hapus->next;
            delete hapus;
        }
        cout << "Data \"" << dataDelete << "\" berhasil dihapus dari Linked List." << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void hapusBelakang() {
    if(isEmpty() == 0) {
        int n;
        cout << "Masukkan nilai N (Hapus node ke-N dari belakang) : ";
        cin >> n;
        int total = hitungNode();
        
        if(n >= total) {
            TNode *hapus = head;
            dataDelete = hapus->data;
            if(head != tail) {
                head = head->next;
                tail->next = head;
            } else {
                init();
            }
            delete hapus;
        } 
        else if (n <= 1) {
            TNode *hapus = tail;
            dataDelete = hapus->data;
            if(head != tail) {
                TNode *newTail = head;
                while(newTail->next != tail) {
                    newTail = newTail->next;
                }
                tail = newTail;
                tail->next = head;
            } else {
                init();
            }
            delete hapus;
        } 
        else {
            int targetPosisi = total - n + 1;
            TNode *bantu = head;
            for(int i = 1; i < targetPosisi - 1; i++) {
                bantu = bantu->next;
            }
            TNode *hapus = bantu->next;
            dataDelete = hapus->data;
            bantu->next = hapus->next;
            delete hapus;
        }
        cout << "Data \"" << dataDelete << "\" berhasil dihapus dari Linked List." << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void hapusData() {
    if(isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> cari;
        int totalNode = hitungNode();
        TNode *bantu = head;
        TNode *sebelum = tail;
        bool apaDitemukan = false;
        
        for(int i = 0; i < totalNode; i++) {
            if(bantu->data == cari) {
                apaDitemukan = true;
                TNode *hapus = bantu;
                
                if(head == tail) {
                    head = NULL;
                    tail = NULL;
                } else if(hapus == head) { 
                    head = head->next; 
                    tail->next = head; 
                    bantu = head; 
                } else if(hapus == tail) { 
                    tail = sebelum; 
                    tail->next = head; 
                    bantu = head; 
                } else { 
                    sebelum->next = bantu->next; 
                    bantu = bantu->next; 
                }
                delete hapus;
            } else {
                sebelum = bantu; 
                bantu = bantu->next;
            }
        }
        if(apaDitemukan == true) {
            cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List telah dihapus." << endl;
        } else {
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        do {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while(bantu != head);
        cout << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void reset() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        TNode *hapus;
        int urutan = 1;
        do {
            hapus = bantu;
            bantu = bantu->next;
            cout << "Node ke-" << urutan << " dan isinya: " << hapus->data << " telah dihapus." << endl;
            delete hapus;
            urutan++;
        } while(bantu != head);
        init();
        cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void cariData() {
    if(isEmpty() == 0) {
        string cari;
        cout << "Masukan data yang ingin dicari : ";
        cin >> cari;
        TNode *bantu = head;
        TNode *bantuTampilkan;
        bool apaDitemukan = false;

        do {
            if(cari == bantu->data) {
                cout << "Setiap data yang berada di dalam tanda kurung siku ([...]) "
                     << "merupakan data yang anda cari." << endl;
                cout << "Linked List : ";
                bantuTampilkan = head;
                do {
                    if(cari == bantuTampilkan->data) {
                        cout << "[" << bantuTampilkan->data << "] ";
                    } else {
                        cout << bantuTampilkan->data << " ";
                    }
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);
                apaDitemukan = true;
                cout << endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan == false) {
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        TNode *sebelum = tail;
        string nextData;
        bool apaAda = false;

        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

        do {
            if(nextData == bantu->data) {
                apaAda = true;
                break;
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda == true) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;
            if(bantu == head) {
                head = baru;
            }
            cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \"" << nextData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
        }
    } else {
        cout << "Tidak tedapat data pada Linked List." << endl;
    }
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        string prevData;
        bool apaAda = false;

        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

        do {
            if(prevData == bantu->data) {
                apaAda = true;
                break;
            } else {
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda == true) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;
            if(bantu == tail) {
                tail = baru;
            }
            cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \"" << prevData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}