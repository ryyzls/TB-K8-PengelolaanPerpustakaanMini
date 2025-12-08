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
// Randi: KEPUTUSAN
// =======================
void prosesPilihan(int pilih) {
    if(pilih == 1) {
        tambahBuku();         // Orang 5
    } else if(pilih == 2) {
        tampilkanBuku();      // Orang 5
    } else if(pilih == 3) {
        hapusBuku();          // Orang 5
    } else if(pilih == 4) {
        editBuku();           // Orang 5
    } else if(pilih == 5) {
        cariBuku();           // Orang 5
    } else if(pilih == 6) {
        simpanFile();         // Orang 6
    } else if(pilih == 7) {
        muatFile();           // Orang 6
    } else if(pilih == 0) {
        printf(RED"Keluar dari program...\n"RESET);
    } else {
        printf(RED"Menu tidak valid!\n"RESET);
    }
}

