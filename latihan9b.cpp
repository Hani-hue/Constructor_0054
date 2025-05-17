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
