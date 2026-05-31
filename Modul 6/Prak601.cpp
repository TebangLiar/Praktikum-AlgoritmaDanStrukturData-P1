#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <vector>

using namespace std;

void menu_sequential() {
    int data[100];
    cout << "100 data acak telah dibuat:\n";
    cout << "Data: ";
    for(int i = 0; i < 100; i++) {
        data[i] = (rand() % 99) + 1; 
        cout << data[i] << " ";
    }
    cout << "\n\nMasukkan angka yang ingin dicari: ";
    
    int target_cari;
    cin >> target_cari;
    
    int hitung = 0;
    int indeks_akhir = -1;
    
    for(int i = 0; i < 100; i++) {
        if(data[i] == target_cari) {
            hitung++;
            indeks_akhir = i;
        }
    }
    
    if(hitung > 0) {
        cout << "Data ditemukan sebanyak " << hitung << " kali.\n";
        cout << "Kemunculan terakhir pada indeks ke- " << indeks_akhir << ".\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

void menu_binary() {
    int ukuran_vektor;
    cout << "Masukkan ukuran vector: ";
    cin >> ukuran_vektor;
    
    vector<int> data_angka(ukuran_vektor);
    cout << ukuran_vektor << " data acak telah dibuat:\n";
    cout << "Data: ";
    for(int i = 0; i < ukuran_vektor; i++) {
        data_angka[i] = (rand() % 99) + 1;
        cout << data_angka[i] << " ";
    }
    
    cout << "\n\nMasukkan angka yang ingin dicari: ";
    int target_cari;
    cin >> target_cari;
    
    for(int i = 0; i < ukuran_vektor - 1; i++) {
        for(int j = 0; j < ukuran_vektor - i - 1; j++) {
            if(data_angka[j] > data_angka[j+1]) {
                int simpan = data_angka[j];
                data_angka[j] = data_angka[j+1];
                data_angka[j+1] = simpan;
            }
        }
    }
    
    cout << "Data setelah diurutkan:\n";
    cout << "Data: ";
    for(int i = 0; i < ukuran_vektor; i++) {
        cout << data_angka[i] << " ";
    }
    cout << "\n";
    
    int awal = 0;
    int akhir = ukuran_vektor - 1;
    bool ketemu_gak = false;
    
    while(awal <= akhir) {
        int posisi_tengah = (awal + akhir) / 2;
        if(data_angka[posisi_tengah] == target_cari) {
            ketemu_gak = true;
            break;
        } else if(target_cari < data_angka[posisi_tengah]) {
            akhir = posisi_tengah - 1;
        } else {
            awal = posisi_tengah + 1;
        }
    }
    
    if(ketemu_gak) {
        cout << "Angka ditemukan!\n";
    } else {
        cout << "Angka tidak ditemukan!\n";
    }
}

void cetak_penjelasan() {
    cout << "\n--- Penjelasan Perbedaan ---\n";
    cout << "Sequential Searching: Mencari data dengan cara mengecek satu per satu dari elemen pertama hingga terakhir.\n";
    cout << "Binary Searching: Mencari data dengan cara membagi array menjadi dua bagian dan membandingkan nilai tengahnya.\n";
}

int main() {
    srand(time(0));
    int pilihan_menu;
    
    do {
        system("cls");
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih: ";
        cin >> pilihan_menu;
        
        switch(pilihan_menu) {
            case 1:
                menu_sequential();
                break;
            case 2:
                menu_binary();
                break;
            case 3:
                cetak_penjelasan();
                break;
            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program dibuat oleh Ahmad Riyadhi (2510817110004)\n";
                break;
            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi\n";
                break;
        }
        
        if(pilihan_menu != 4) {
            cout << "\nTekan dimanapun untuk melanjutkan...";
            getch();
        }
        
    } while(pilihan_menu != 4);
    
    return 0;
}