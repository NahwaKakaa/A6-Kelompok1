#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk format tabel

using namespace std;

// Struktur data untuk menyimpan informasi bahan makanan
struct BahanMakanan {
    string nama;
    string tanggalKadaluarsa;
    int jumlahStok;
};

// Fungsi untuk menampilkan tabel bahan makanan
void tampilkanBahan(const vector<BahanMakanan>& bahanMakanan) {
    if (bahanMakanan.empty()) {
        cout << "Daftar bahan makanan kosong.\n";
        return;
    }

    cout << left << setw(20) << "Nama" 
         << setw(20) << "Tanggal Kadaluarsa" 
         << setw(10) << "Jumlah Stok" << endl;
    cout << string(50, '-') << endl;

    for (const auto& bahan : bahanMakanan) {
        cout << left << setw(20) << bahan.nama
             << setw(20) << bahan.tanggalKadaluarsa
             << setw(10) << bahan.jumlahStok << endl;
    }
}

// Fungsi untuk menambahkan bahan makanan
void tambahBahan(vector<BahanMakanan>& bahanMakanan) {
    BahanMakanan bahanBaru;

    cout << "Masukkan nama bahan makanan: ";
    cin.ignore(); // Membersihkan buffer input
    getline(cin, bahanBaru.nama);
    cout << "Masukkan tanggal kadaluarsa (YYYY-MM-DD): ";
    getline(cin, bahanBaru.tanggalKadaluarsa);
    cout << "Masukkan jumlah stok: ";
    cin >> bahanBaru.jumlahStok;

    bahanMakanan.push_back(bahanBaru);
    cout << "Bahan makanan berhasil ditambahkan.\n";
}

// Fungsi untuk menghapus bahan makanan
void hapusBahan(vector<BahanMakanan>& bahanMakanan) {
    string namaHapus;
    cout << "Masukkan nama bahan makanan yang ingin dihapus: ";
    cin.ignore();
    getline(cin, namaHapus);

    auto it = find_if(bahanMakanan.begin(), bahanMakanan.end(),
                      [&namaHapus](const BahanMakanan& bahan) {
                          return bahan.nama == namaHapus;
                      });

    if (it != bahanMakanan.end()) {
        bahanMakanan.erase(it);
        cout << "Bahan makanan berhasil dihapus.\n";
    } else {
        cout << "Bahan makanan tidak ditemukan.\n";
    }
}

// Fungsi untuk mencari bahan makanan
void cariBahan(const vector<BahanMakanan>& bahanMakanan) {
    string kataKunci;
    cout << "Masukkan kata kunci untuk mencari bahan makanan: ";
    cin.ignore();
    getline(cin, kataKunci);

    bool ditemukan = false;
    for (const auto& bahan : bahanMakanan) {
        if (bahan.nama.find(kataKunci) != string::npos) {
            if (!ditemukan) {
                cout << "Hasil pencarian:\n";
                cout << left << setw(20) << "Nama"
                     << setw(20) << "Tanggal Kadaluarsa"
                     << setw(10) << "Jumlah Stok" << endl;
                cout << string(50, '-') << endl;
                ditemukan = true;
            }
            cout << left << setw(20) << bahan.nama
                 << setw(20) << bahan.tanggalKadaluarsa
                 << setw(10) << bahan.jumlahStok << endl;
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada bahan makanan yang cocok dengan kata kunci.\n";
    }
}

// Fungsi utama
int main() {
    vector<BahanMakanan> bahanMakanan;
    int pilihan;

    do {
        cout << "\n=== Aplikasi Manajemen Bahan Makanan ===\n";
        cout << "1. Tambah Bahan Makanan\n";
        cout << "2. Tampilkan Daftar Bahan Makanan\n";
        cout << "3. Hapus Bahan Makanan\n";
        cout << "4. Cari Bahan Makanan\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBahan(bahanMakanan);
                break;
            case 2:
                tampilkanBahan(bahanMakanan);
                break;
            case 3:
                hapusBahan(bahanMakanan);
                break;
            case 4:
                cariBahan(bahanMakanan);
                break;
            case 5:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
