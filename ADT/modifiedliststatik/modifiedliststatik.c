/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include <stdio.h>
#include "modifiedliststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
    int i;
    for (i = 0; i < MAX_USERS; i++)
    {
        strcpy(ELMT(*l, i).username, "");
        strcpy(ELMT(*l, i).password, "");
        strcpy(ELMT(*l, i).bio, "");
        strcpy(ELMT(*l, i).weton, "");
        ELMT(*l, i).isPrivate = false; // Private defaults to false
        createMatrix(5, 10, &(ELMT(*l, i).profile));
        (ELMT(*l, i).isPrivate = false);
        CreateEmptyStack(&(ELMT(*l, i).draf));
    }
}

int listLength(ListStatik l)
{
    int i;
    int count = 0;
    for (i = 0; i < MAX_USERS; i++)
    {
        if (ELMT(l, i).username[0] != '\0')
        {
            count += 1;
        }
    }
    return count;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l)
{
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    if (listLength(l) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* *** Test List penuh *** */
boolean isFull(ListStatik l)
{
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    if (listLength(l) == CAPACITY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printList(ListStatik *pengguna)
{
    int i;
    printf("[");
    for (i = 0; i < listLength(*pengguna); i++)
    {
        printf("%s", ELMT(*pengguna, i).username);
        if (i < listLength(*pengguna) - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

/* Check apakah user privat */
boolean isUserPrivate(User user)
/* Mengembalikan true bila akun user privat */
/* Mengembalikan false bila akun user public */
{
    return user.isPrivate;
}

void SetPhoneNum(ListStatik *l, int userIndex, MASUKAN nohp)
{
    if (userIndex >= 0 && userIndex < MAX_USERS)
    {
        ELMT(*l, userIndex).phone_num = nohp;
    }
}

void SetBio(ListStatik *l, int userIndex, const char *bio)
{
    if (userIndex >= 0 && userIndex < MAX_USERS)
    {
        strcpy(ELMT(*l, userIndex).bio, bio);
    }
}

void SetWeton(ListStatik *l, int userIndex, const char *weton)
{
    if (userIndex >= 0 && userIndex < MAX_USERS)
    {
        strcpy(ELMT(*l, userIndex).weton, weton);
    }
}

void SetProfile(ListStatik *l, int userIndex, Matrix *profile)
{
    if (userIndex >= 0 && userIndex < MAX_USERS)
    {
        ELMT(*l, userIndex).profile = *profile;
    }
}

void SetIsPrivate(ListStatik *l, int userIndex, boolean *status)
{
    if (userIndex >= 0 && userIndex < MAX_USERS)
    {
        ELMT(*l, userIndex).isPrivate = *status;
    }
}

// TES

// int main() {
//     ListStatik l;
//     CreateListStatik(&l);
//     printf("list length: %d\n", listLength(l));

//     char username_temp[MAX_USERNAME_LENGTH];
//     printf("Masukkan nama: ");
//     fgets(username_temp, MAX_USERNAME_LENGTH, stdin);
//     username_temp[strcspn(username_temp, "\n")] = '\0';
//     strcpy(ELMT(l, 0).username, username_temp);
//     printList(l);
//     printf("list length: %d\n", listLength(l));
// }