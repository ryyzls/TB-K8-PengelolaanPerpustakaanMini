#include <stdio.h>
#include <string.h>
#define MAX 100

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

void inputJudul(char *judul) {
    printf(YELLOW"Masukkan Judul Buku   : "RESET);
    fgets(judul, 50, stdin);
    judul[strcspn(judul, "\n")] = 0;
}

void inputPenulis(char *penulis) {
    printf(YELLOW"Masukkan Penulis      : "RESET);
    fgets(penulis, 50, stdin);
    penulis[strcspn(penulis, "\n")] = 0;
}

int inputTahun() {
    int tahun;
    printf(YELLOW"Masukkan Tahun Terbit : "RESET);
    scanf("%d", &tahun);
    getchar();
    return tahun;
}

void tampilMenu() {
    printf("\n"MAGENTA"=======================================\n");
    printf("|    MENU PENGELOLAAN PERPUSTAKAAN    |\n");
    printf("=======================================\n"RESET);
    printf(MAGENTA"|"RESET YELLOW" 1. Tambah Buku                      "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"|"RESET YELLOW" 2. Lihat Semua Buku                 "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"|"RESET YELLOW" 3. Hapus Buku                       "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"|"RESET YELLOW" 4. Edit Buku                        "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"|"RESET YELLOW" 5. Cari Buku                        "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"|"RESET YELLOW" 6. Simpan ke File                   "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"|"RESET YELLOW" 7. Load dari File                   "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"|"RESET RED" 0. Keluar                           "RESET MAGENTA"|\n"RESET);
    printf(MAGENTA"=======================================\n"RESET);
    printf(BLUE"Pilih Menu: "RESET);
}
