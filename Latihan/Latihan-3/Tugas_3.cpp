#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int n, x;
    
    cout << "Masukkan nilai N dan target X: ";
    cin >> n >> x;

    if(n < 10) {
        cout << "N minimal harus 10" << endl;
        return 0;
    }

    int arr[1000]; 
    srand(time(0));

    cout << "\n--- HASIL ARRAY ACAK (1-25) ---" << endl;
    cout << "Array Awal : ";
    for(int i = 0; i < n; i++) {
        arr[i] = (rand() % 25) + 1; 
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int sementara = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = sementara;
            }
        }
    }

    cout << "Array Urut : ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    int jumlah_pasangan = 0;

    for(int i = 0; i < n - 1; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int angka_dicari = x - arr[i];
        int batas_kiri = i + 1;
        int batas_kanan = n - 1;
        bool ditemukan = false;

        while(batas_kiri <= batas_kanan) {
            int titik_tengah = (batas_kiri + batas_kanan) / 2;
            
            if(arr[titik_tengah] == angka_dicari) {
                ditemukan = true;
                break;
            } else if(arr[titik_tengah] < angka_dicari) {
                batas_kiri = titik_tengah + 1;
            } else {
                batas_kanan = titik_tengah - 1;
            }
        }

        if(ditemukan) {
            jumlah_pasangan++;
        }
    }

    cout << "Output:" << endl;
    cout << jumlah_pasangan << endl;
    cout << "(Ditemukan " << jumlah_pasangan << " pasangan angka yang jika dijumlahkan bernilai " << x << ")" << endl;

    return 0;
}