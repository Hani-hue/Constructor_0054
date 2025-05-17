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
