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

void tambahbuku()
{
  struct buku b;
  b.id = jumlah + 1;

  inputjudul(b.judul);
  inputpenulis(b.penulis);
  b.tahun = inputTahun();

  daftar[jumlah] = b;
  jumlah++;

  printf(GREEN"Buku berhasil di tambahkan!\n"RESET);
}

void tampilkanBuku() 
{
  if(jumlah == 0)
  {
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


