#include "utas.h"
#include "ADTUsed/listlinier/listlinierForUtas.h"

// Membuat sebuah Utas baru dari kicauan yang sudah ada, Akan di-set ID Utas dan pointer kicauan
void CreateUtas(UTAS *u, Kicauan *kicauan)
{
    (*u).tweet = kicauan;
    IDUtas(*u) = 0;
    Sambungan(*u) = NULL;
}

// Menyambung Utas
void SAMBUNG_UTAS(UTAS *u, char text[MAX_CHAR], int index)
{
    Address N = newThreadNode(text);
    Address P = Sambungan(*u); // P merupakan alamat kicauan sambungan pertama
    while (NextThread(P) != NULL)
    {
        P = NextThread(P);
    }
    NextThread(P) = N;
}

// Mencetak Utas (Kalo Fornat kicauan ga diubah)
void CETAK_UTAS(UTAS u)
{
    // Cetak kicauan utama
    printf(" |%d\n", ID(*(u.tweet)));
    printf(" |%s\n", AUTHOR(*(u.tweet)));
    printf(" |");
    displayTime(DATETIME(*(u.tweet)));
    printf("\n");
    printf(" |%s\n", TEXT(*(u.tweet)));
    printf("n");

    // Cetak kicauan sambungan
    Address P = Sambungan(u);
    int idx = 1;
    while (P != NULL)
    {
        printf("   | INDEX = %d\n", idx);
        printf("   |%s\n", AUTHOR(*(u.tweet)));
        printf("   |");
        displayTime(TimeThread(P));
        printf("\n");
        printf("   |%s\n", TextThread(P));
        printf("\n");
        P = NextThread(P);
        idx = idx + 1;
    }
}

// Menghapus kicauan sambungan pada ID Utas tertentu, dan index kicauan sambungan tertentu
void HAPUS_UTAS(UTAS *u, int idx)
{ // TO DO : NAMBAHIN VERIFIKASI AUTHOR, NGECEK ID UTAS
    Address P = Sambungan(*u);
    if (lengthThreads(P) < idx)
    {
        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", idx);
    }
    else
    {
        deleteAtThreads(P, idx);
        printf("Kicauan sambungan berhasil dihapus!\n");
    }
}
