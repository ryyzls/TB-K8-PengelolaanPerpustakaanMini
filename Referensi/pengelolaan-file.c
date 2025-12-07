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


void simpanFile() {
    FILE *file = fopen("buku.txt", "w");

    if(file == NULL) {
        printf(RED"Gagal membuka file!\n"RESET);
        return;
    }

    for(int i=0; i<jumlah; i++) {
        fprintf(file, "%d|%s|%s|%d\n",
            daftar[i].id,
            daftar[i].judul,
            daftar[i].penulis,
            daftar[i].tahun);
    }

    fclose(file);
    printf(GREEN"Data berhasil disimpan ke file!\n"GREEN);
}

void muatFile() {
    FILE *file = fopen("buku.txt", "r");
    if(file == NULL) {
        printf(RED"File tidak ditemukan.\n"RED);
        return;
    }

    jumlah = 0;
    while(!feof(file)) {
        struct Buku b;
        if(fscanf(file, "%d|%49[^|]|%49[^|]|%d\n",
            &b.id, b.judul, b.penulis, &b.tahun) == 4) {
            daftar[jumlah] = b;
            jumlah++;
        }
    }

    fclose(file);
    printf(GREEN"Data berhasil dimuat dari file!\n"RESET);
}
