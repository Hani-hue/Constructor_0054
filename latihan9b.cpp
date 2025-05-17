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
