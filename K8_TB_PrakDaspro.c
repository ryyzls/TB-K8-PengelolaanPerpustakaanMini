// Kelompok 8 - Pengelolaan Perpustakaan Mini
// Anggota Kelompok :
// Dwi Charima Husni                (251402088)
// Jesqueen Maria Purba             (251402099)
// Fahri Arizal                     (251402102)
// Muhammad Dzakwan Ismail Rangkuti (251402014)
// Rasyid Arija Azron Ritonga       (251402020)
// Randi Abdiansyah                 (251402138)

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
    
    char keyword[50];
    int tahunCari;
    int ditemukan = 0;

    printf("\n=== HASIL PENCARIAN ===\n");

    if(pilih == 1) {
        printf("Masukkan Judul Buku: ");
        fgets(keyword, 50, stdin);
        keyword[strcspn(keyword, "\n")] = 0;

        for(int i=0; i<jumlah; i++) {
            if(strstr(daftar[i].judul, keyword)) {
                printf("%d. Judul Buku : %s\n   Penulis    : %s \n   Tahun      : %d\n",
                    daftar[i].id, daftar[i].judul, daftar[i].penulis, daftar[i].tahun);
                ditemukan = 1;
            }
        }
    }
    else if(pilih == 2) {
        printf("Masukkan Penulis: ");
        fgets(keyword, 50, stdin);
        keyword[strcspn(keyword, "\n")] = 0;

        for(int i=0; i<jumlah; i++) {
            if(strstr(daftar[i].penulis, keyword)) {
                printf("%d. Judul Buku : %s\n   Penulis    : %s \n   Tahun      : %d\n",
                    daftar[i].id, daftar[i].judul, daftar[i].penulis, daftar[i].tahun);
                ditemukan = 1;
            }
        }
    }
    else if(pilih == 3) {
        printf("Masukkan Tahun: ");
        scanf("%d", &tahunCari);
        getchar();

        for(int i=0; i<jumlah; i++) {
            if(daftar[i].tahun == tahunCari) {
                printf("%d. Judul Buku : %s\n   Penulis    : %s \n   Tahun      : %d\n",
                    daftar[i].id, daftar[i].judul, daftar[i].penulis, daftar[i].tahun);
                ditemukan = 1;
            }
        }
    }

    if(!ditemukan) printf(RED"Tidak ada buku yang cocok.\n"RESET);
}

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

void prosesPilihan(int pilih) {
    if(pilih == 1) {
        tambahBuku();         
    } else if(pilih == 2) {
        tampilkanBuku();      
    } else if(pilih == 3) {
        hapusBuku();          
    } else if(pilih == 4) {
        editBuku();           
    } else if(pilih == 5) {
        cariBuku();           
    } else if(pilih == 6) {
        simpanFile();
    }
