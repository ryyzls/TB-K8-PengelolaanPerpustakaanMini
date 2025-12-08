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

struct Buku {
    int id;
    char judul[50];
    char penulis[50];
    int tahun;
};

struct Buku daftar[MAX];
int jumlah = 0;

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
void tambahBuku() {
    struct Buku b;
    b.id = jumlah + 1;

    inputJudul(b.judul);
    inputPenulis(b.penulis);
    b.tahun = inputTahun();

    daftar[jumlah] = b;
    jumlah++;

    printf(GREEN"Buku berhasil ditambahkan!\n"RESET);
}

void tampilkanBuku() {
    if(jumlah == 0) {
        printf(RED"Belum ada buku.\n"RESET);
        return;
    }

    printf("\n"BLUE"======================================================================\n");
    printf("| %-2s | %-30s | %-20s | %-4s |\n", "ID", "Judul Buku", "Penulis", "Tahun");
    printf("======================================================================\n"RESET);

    for(int i=0; i<jumlah; i++) {
        printf(BLUE"|"RESET GREEN" %-2d "RESET BLUE"|"RESET GREEN" %-30s "RESET BLUE"|"RESET GREEN" %-20s "RESET BLUE"|"RESET GREEN" %-5d "RESET BLUE"|"RESET"\n",
            daftar[i].id,
            daftar[i].judul,
            daftar[i].penulis,
            daftar[i].tahun);
    }
    printf(BLUE"======================================================================\n"RESET);
}

void hapusBuku() {
    int id;
    printf(YELLOW"Masukkan ID buku yang ingin dihapus: "RESET);
    scanf("%d", &id);
    getchar();

    int index = -1;
    for(int i=0; i<jumlah; i++) {
        if(daftar[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf(RED"ID tidak ditemukan!\n"RESET);
        return;
    }

    for(int i=index; i<jumlah-1; i++) {
        daftar[i] = daftar[i+1];
        daftar[i].id = i + 1;
    }

    jumlah--;
    printf(GREEN"Buku berhasil dihapus!\n"RESET);
}

void editBuku() {
    int id;
    printf(YELLOW"Masukkan ID buku yang ingin diedit: "RESET);
    scanf("%d", &id);
    getchar();

    int index = -1;
    for(int i=0; i<jumlah; i++) {
        if(daftar[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf(RED"ID tidak ditemukan!\n"RESET);
        return;
    }

    inputJudul(daftar[index].judul);
    inputPenulis(daftar[index].penulis);
    daftar[index].tahun = inputTahun();

    printf(GREEN"Buku berhasil diedit!\n"GREEN);
}

void cariBuku() {
    if(jumlah == 0) {
        printf(RED"Tidak ada buku untuk dicari.\n"RED);
        return;
    }

    int pilih;
    printf("\n"BLUE"======================\n");
    printf("| Cari Berdasarkan:  |\n");
    printf("======================\n"RESET);
    printf(BLUE"|"RESET YELLOW" 1. Judul Buku      "RESET BLUE"|\n"RESET);
    printf(BLUE"|"RESET YELLOW" 2. Penulis         "RESET BLUE"|\n"RESET);
    printf(BLUE"|"RESET YELLOW" 3. Tahun           "RESET BLUE"|\n"RESET);
    printf(BLUE"|"RESET MAGENTA" 4. Kembali ke Menu "RESET BLUE"|\n"RESET);
    printf(BLUE"======================\n"RESET);
    printf(BLUE"Pilih: "RESET);
    scanf("%d", &pilih);
    getchar();

    if(pilih == 4) {
        return;
    }
