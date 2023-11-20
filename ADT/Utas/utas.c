#include "utas.h"
#include <stdio.h>

int isIdUtasValid(ListUtas li, int idx)
// Mengembalikan indeks pada array  jika valid, dan -1 jika tidak valid
{
    int id = -1;
    for (int i = 0; i < listUtasLength(li); i++)
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

boolean isUtasUser(UTAS u, User userloggedin)
{
    return (isSame(strToMASUKAN(AuthorUtas(u), 20), userloggedin.username));
}

boolean isKicauanUser(Kicauan k, User userloggedin)
{
    return (isSame(strToMASUKAN((*AUTHOR(k)).username, 20), userloggedin.username));
}

void BUAT_UTAS(ListDinKicauan lk, ListUtas lu, User userloggedIn, int idk) // Indeks Kicauan dimulai dari 1
{
    MASUKAN teks;
    UTAS utas;
    if (isIdxEffListDinKicauan(lk, idk - 1)) // ID Kicauan Valid, fungsinya ngecek dari 0..
    {
        if (isKicauanUser((InfoKicauan((BUFFER_LDK(lk))[idk - 1])), userloggedIn)) // ID Kicauan Milik sendiri
        {

            CreateUtas(&utas, &(InfoKicauan((BUFFER_LDK(lk))[idk - 1])), listUtasLength(lu) + 1);

            printf("Utas berhasil dibuat!\n\n");
            printf("Masukkan kicauan:\n");
            baca(&teks);

            SambungUtasLast(&utas, MASUKANToStr(teks));

            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
            baca(&teks);
            while (isSame(teks, "YA"))
            {
                printf("Masukkan kicauan:\n");
                baca(&teks);
                SambungUtasLast(&utas, MASUKANToStr(teks));
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

void SAMBUNG_UTAS(int idU, int index, ListUtas *lu, User userloggedin)
{
    MASUKAN teks;
    int id = isIdUtasValid(*lu, idU);

    if (id != -1) // ID Utas Valid
    {
        if (isUtasUser((BUFFERListDinUtas(*lu))[idU], userloggedin)) // ID Utas milik user
        {
            if (isIndexSambunganValid(KicauanSambungan(BUFFERListDinUtas(*lu)[id]), index)) // Indeks sambungan valid
            {
                printf("Masukkan kicauan:\n");
                baca(&teks);
                SambungUtasAt(&(BUFFERListDinUtas(*lu))[id], MASUKANToStr(teks), index);
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

void HAPUS_UTAS(ListUtas *li, int idU, int index, User userloggedin)
{
    int id = isIdUtasValid(*li, idU);

    if (id != -1) // ID Utas Valid
    {
        if (isUtasUser(BUFFERListDinUtas(*li)[id], userloggedin)) // Utas dengan ID tersebut milik user terlogin
        {
            if (isIndexSambunganValid(KicauanSambungan(BUFFERListDinUtas(*li)[id]), index)) // Index Kicauan Sambungan Valid
            {
                deleteSambungan(&BUFFERListDinUtas(*li)[id], index);
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
        printf("Utas tidak ditemukan!\n");
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
            printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        }
    }
    else
    {
        printf("Utas tidak ditemukan!\n");
    }
}