#include "utas.h"
#include <stdio.h>

int isIdUtasValid(ListUtas li, int idx)
// Mengembalikan indeks pada array  jika valid, dan -1 jika tidak valid
{
    int id = -1;
    for (int i = 0; i < listLength(li); i++)
    {
        if (IDUtas(BUFFERListDinUtas(li)[i]) == idx)
        {
            id = i;
            break;
        }
    }
    return id;
}

boolean isIndexSambunganValid(threads u, int index)
{
    return (index > 0 && index <= lengthThreads(u));
}

boolean isUtasUser(UTAS u)
{
    return (compareString((*currentUser).username, AuthorUtas(u), 20));
}

boolean isKicauanUser(Kicauan k)
{
    return (compareString((*currentUser).username, AUTHOR(k).username, 20))
}

void BUAT_UTAS(int idk)
{
    if (isIdxEffListDinKicauan(listKicauan, idk)) // ID Kicauan Valid
    {
        if (isKicauanUser(BUFFER_LDK(idk - 1))) // ID Kicauan Milik sendiri
        {
            MASUKAN teks;
            printf("Utas berhasil dibuat!\n\n");
            printf("Masukkan kicauan:");
            baca(&teks);

            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
            baca(&teks);
            while (isSame(teks, "YA"))
            {
                printf("Masukkan kicauan:");
                baca(&teks);
                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                baca(&teks);
            }
            printf("Utas selesai!\n");
        }
        else
        {
            printf("Utas ini bukan milik anda!\n");
        }
    }
    else
    {
        printf("Kicauan tidak ditemukan");
    }
}

void SAMBUNG_UTAS(int idU, int index, ListUtas *li)
{
    MASUKAN teks;
    int id = isIdUtasValid(*li, idU);

    if (id != -1) // ID Utas Valid
    {
        if (isUtasUser(BUFFERListDinUtas(*li))[id]) // ID Utas milik user
        {
            if (isIndexSambunganValid(KicauanSambungan(BUFFERListDinUtas(*li)[id]), index)) // Indeks sambungan valid
            {
                printf("Masukkan kicauan:\n");
                baca(&teks);
                SambungUtas(&(BUFFERListDinUtas(*li))[id], teks.TabMASUKAN, index);
            }
            else
            {
                printf("Index terlalu tinggi!\n");
            }
        }
        else
        {
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
    }
    else
    {
        printf("Utas tidak ditemukan!\n");
    }
}

void HAPUS_UTAS(int idU, int index, ListUtas *li)
{
    int id = isIdUtasValid(*li, idU);

    if (id != -1) // ID Utas Valid
    {
        if (isUtasUser(BUFFERListDinUtas(*li)[id])) // Utas dengan ID tersebut milik user terlogin
        {
            if (isIndexSambunganValid(KicauanSambungan(BUFFERListDinUtas(*li)[id]))) // Index Kicauan Sambungan Valid
            {
                deleteSambungan(BUFFERListDinUtas(*li)[id], index);
            }
            else
            {
                printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!", index);
            }
        }
        else
        {
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        }
    }
    else
    {
        printf("Utas tidak ditemukan!\n")
    }
}

void CETAK_UTAS(int idU, ListUtas li)
{
    boolean friend; // TO DO : UPDATE HUBUNGAN TEMAN

    if (isIdUtasValid(li, idU))
    {
        if (friend)
        {
            displayUtas((BUFFERListDinUtas(li))[idU - 1]);
        }
        else
        {
            printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n")
        }
    }
    else
    {
        printf("Utas tidak ditemukan!\n")
    }
}