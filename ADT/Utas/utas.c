#include "utas.h"
#include <stdio.h>

boolean isKicauExistinUtas(AddressKicauan kicau)
{
    boolean exist = false;
    for (int i = 0; i < listUtasLength(listUtas); i++)
    {
        if (ID(InfoKicauan(KicauanUtama(BUFFERListDinUtas(listUtas)[i]))) == ID(InfoKicauan(kicau)))
        {
            exist = true;
            break;
        }
    }
    return exist;
}

int isIdUtasValid(int idx)
// Mengembalikan true/false
{
    return (idx >= 1 && idx <= listUtasLength(listUtas));
}

boolean isIndexSambunganValid(threads u, int index)
{
    return (index >= 1 && index <= lengthThreads(u));
}

boolean isUtasUser(UTAS u)
{
    return (isSame(strToMASUKAN(AUTHOR(InfoKicauan(KicauanUtama(u)))->username, 20), (*currentUser).username));
}

boolean isKicauanUser(AddressKicauan k)
{
    return (isSame(strToMASUKAN(AUTHOR(InfoKicauan(k))->username, 20), (*currentUser).username));
}

void BUAT_UTAS(int idk) // Indeks Kicauan dimulai dari 1
{
    MASUKAN teks;
    UTAS utas;

    printf("MASUK BUAT UTAS\n");
    // Validasi Apakah User Sudah login
    if (!isUserLoggedIn())
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    // Validasi Apakah indeks kicauan terdefinisi
    if (!isIdxEffListDinKicauan(listKicauan, idk - 1))
    {
        printf("Kicauan tidak ditemukan\n");
        return;
    }

    // Validasi Apakah kicauan sudah dibuat menjadi utas
    if (isKicauExistinUtas(BUFFER_LDK(listKicauan)[idk - 1]))
    {
        printf("Kicauan sudah dibuat menjadi utas!\n");
        return;
    }

    // Validasi Apakah kicauan milik user yang login
    if (!isKicauanUser(BUFFER_LDK(listKicauan)[idk - 1]))
    {
        printf("Utas ini bukan milik anda!\n");
        return;
    }

    // Semua prekondisi telah memenuhi
    CreateUtas(&utas, BUFFER_LDK(listKicauan)[idk - 1], listUtasLength(listUtas) + 1);

    printf("Utas berhasil dibuat!\n\n");
    printf("Masukkan kicauan:\n");
    baca(&teks);

    // Handle Jika input spasi semua
    if (isAllSpace(teks))
    {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
        return;
    }

    SambungUtasLast(&utas, MASUKANToStr(teks), getCurrTime());

    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
    baca(&teks);
    while (isSame(teks, "YA"))
    {
        printf("Masukkan kicauan:\n");
        baca(&teks);

        // Handle Jika input spasi semua
        if (isAllSpace(teks))
        {
            printf("Kicauan tidak boleh hanya berisi spasi!\n");
            return;
        }

        SambungUtasLast(&utas, MASUKANToStr(teks), getCurrTime());
        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
        baca(&teks);
    }
    insertUtas(utas, &listUtas);
    printf("Utas selesai!\n");
}

void SAMBUNG_UTAS(int idU, int index)
{
    MASUKAN teks;

    // Validasi Apakah User Sudah login
    if (!isUserLoggedIn())
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    //  Utas tidak terdefinisi
    if (!isIdUtasValid(idU))
    {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    // Utas bukan milik user
    if (!isUtasUser((BUFFERListDinUtas(listUtas))[idU - 1]))
    {
        printf("Anda tidak bisa menyambung utas ini!\n");
        return;
    }

    if (!isIndexSambunganValid(KicauanSambungan(BUFFERListDinUtas(listUtas)[idU - 1]), index))
    {
        printf("Index terlalu tinggi!\n");
        return;
    }

    printf("Masukkan kicauan:\n");
    baca(&teks);

    // Handle Jika input spasi semua
    if (isAllSpace(teks))
    {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
        return;
    }

    SambungUtasAt(&(BUFFERListDinUtas(listUtas))[idU - 1], MASUKANToStr(teks), index);
}

void HAPUS_UTAS(int idU, int index)
{
    printf("MASUK HAPUS UTAS\n");

    // Validasi Apakah User Sudah login
    if (!isUserLoggedIn())
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    // ID Utas tidak valid
    if (!isIdUtasValid(idU))
    {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    // Utas bukan milik user
    if (!isUtasUser(BUFFERListDinUtas(listUtas)[idU - 1]))
    {
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        return;
    }

    // Index kicauan sambungan tidak ada
    if (!(isIndexSambunganValid(KicauanSambungan(BUFFERListDinUtas(listUtas)[idU - 1]), index)))
    {
        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        return;
    }

    deleteSambungan(&BUFFERListDinUtas(listUtas)[idU - 1], index);
    printf("Kicauan sambungan berhasil dihapus!\n");
}

void CETAK_UTAS(int idU)
{
    // Validasi Apakah User Sudah login
    if (!isUserLoggedIn())
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    // ID Utas tidak ditemukan
    if (!isIdUtasValid(idU))
    {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    // ID Utas milik akun private dan belum berteman dengan user login
    if (isUserPrivate(*AUTHOR(InfoKicauan(KicauanUtama(BUFFERListDinUtas(listUtas)[idU - 1])))) && !(areFriendsEachOthers(*currentUser, *AUTHOR(InfoKicauan(KicauanUtama(BUFFERListDinUtas(listUtas)[idU - 1]))))))
    {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        return;
    }
    displayUtas((BUFFERListDinUtas(listUtas))[idU - 1]);
}