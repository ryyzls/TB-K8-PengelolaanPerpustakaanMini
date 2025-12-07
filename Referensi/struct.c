#include <stdio.h>
#include <string.h>
#define MAX 100
// Kode warna
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// =======================
// Jesqueen: STRUCT
// =======================
struct Buku { 
    int id;
    char judul[50];
    char penulis[50];
    int tahun;
};

struct Buku daftar[MAX];
int jumlah = 0;




