#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Buku
{
public:
    string judul;
    string penulis;
    bool status_peminjaman; // true jika dipinjam, false jika tidak
    string dipinjam_oleh;   // Nama peminjam

    Buku(string judul, string penulis, bool status_peminjaman) : judul(judul), penulis(penulis), status_peminjaman(status_peminjaman), dipinjam_oleh("") {}
};

class Petugas
{
public:
    string nama;
    string id_petugas;
    vector<Buku *> daftar_buku_akses; // Daftar pointer Buku yang dapat diakses petugas
    Petugas(std::string nama, std::string id_petugas) : nama(nama), id_petugas(id_petugas) {}

    void dapatMengaksesBuku(Buku *buku)
    {
        daftar_buku_akses.push_back(buku);
    }

    void prosesPeminjaman(Buku *buku, std::string peminjam)
    {
        bool akses_diberikan = false;
        for (Buku *buku_akses : daftar_buku_akses)
        {
            if (buku_akses == buku)
            {
                akses_diberikan = true;
                break;
            }
        }

        if (akses_diberikan && !buku->status_peminjaman)
        {
            buku->status_peminjaman = true;
            buku->dipinjam_oleh = peminjam;
            std::cout << buku->judul << " berhasil dipinjam oleh " << peminjam << "." << std::endl;
        }
        else if (buku->status_peminjaman)
        {
            std::cout << "Maaf, " << buku->judul << " sedang tidak tersedia." << std::endl;
        }
        else
        {
            std::cout << "Petugas ini tidak memiliki akses untuk meminjamkan buku ini." << std::endl;
        }
    }

    void prosesPengembalian(Buku *buku)
    {
        bool akses_diberikan = false;
        for (Buku *buku_akses : daftar_buku_akses)
        {
            if (buku_akses == buku)
            {
                akses_diberikan = true;
                break;
            }
        }

        if (akses_diberikan && buku->status_peminjaman)
        {
            buku->status_peminjaman = false;
            buku->dipinjam_oleh = "";
            std::cout << buku->judul << " berhasil dikembalikan." << std::endl;
        }
        else if (!buku->status_peminjaman)
        {
            std::cout << buku->judul << " saat ini tidak sedang dipinjam." << std::endl;
        }
        else
        {
            std::cout << "Petugas ini tidak memiliki akses untuk menerima pengembalian buku ini." << std::endl;
        }
    }
};

class Admin : public Petugas
{
public:
    string level_akses;

    Admin(string nama, string id_petugas, string level_akses) : Petugas(nama, id_petugas), level_akses(level_akses) {}

    void menambahkanBuku(std::vector<Buku> &daftar_buku, Buku buku_baru)
    {
        daftar_buku.push_back(buku_baru);
        cout << buku_baru.judul << " berhasil ditambahkan ke daftar buku." << endl;
    }
};

int main()
{
    Buku buku1("Laskar Pelangi", "Andrea Hirata", false);
    Buku buku2("Bumi Manusia", "Pramoedya Ananta Toer", false);
    vector<Buku> daftar_buku;
    daftar_buku.push_back(buku1);
    daftar_buku.push_back(buku2);
    Petugas petugas1("Budi", "P001");
    petugas1.dapatMengaksesBuku(&daftar_buku[0]); // Memberikan akses ke buku1 (perlu pointer)
    petugas1.prosesPeminjaman(&daftar_buku[0], "Andi");
    petugas1.prosesPengembalian(&daftar_buku[0]);

    Admin admin1("Siti", "A001", "Tinggi");
    admin1.menambahkanBuku(daftar_buku, Buku("Negeri 5 Menara", "Ahmad Fuadi", false));

    return 0;
}