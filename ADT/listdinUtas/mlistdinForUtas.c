#include <stdio.h>
#include "../listlinierUtas/listlinierForUtas.h"
#include "../modifiedliststatik/modifiedliststatik.h"
#include "../tree/tree.h"
#include "../datetime/datetime.h"
#include "../time/time.h"
#include "../masukan/masukan.h"
#include "listdinForUtas.h"

char currentChar;
boolean EOP;

int main()
{
    // Create User
    User Budi;
    strcpy(Budi.username, "B. Sitompel");
    User Rusdi;
    strcpy(Rusdi.username, "Rusdi K.");

    User Sahad;
    strcpy(Sahad.username, "Hassans");

    // Create AddressKicauans
    AddressKicauan kicau1;
    ID(InfoKicauan(kicau1)) = 1;
    strcpy(TEXT(InfoKicauan(kicau1)), "This is Kicau 1");
    AUTHOR(InfoKicauan(kicau1)) = &Budi;
    DATETIME(InfoKicauan(kicau1)) = getCurrTime();

    AddressKicauan kicau2;
    ID(InfoKicauan(kicau2)) = 2;
    strcpy(TEXT(InfoKicauan(kicau2)), "This is Kicau 2");
    AUTHOR(InfoKicauan(kicau2)) = &Rusdi;
    DATETIME(InfoKicauan(kicau2)) = getCurrTime();

    AddressKicauan kicau3;
    ID(InfoKicauan(kicau3)) = 3;
    strcpy(TEXT(InfoKicauan(kicau3)), "This is Kicau 3");
    AUTHOR(InfoKicauan(kicau3)) = &Budi;
    DATETIME(InfoKicauan(kicau3)) = getCurrTime();

    // Create Utas
    UTAS utas1, utas2, utas3;
    CreateUtas(&utas1, kicau1, 1);
    CreateUtas(&utas2, kicau2, 2);
    CreateUtas(&utas3, kicau3, 3);

    // Looping Input
    printf("Input Budi\n");
    char teks[20];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", &teks);
        insertLastThreadForConfig(utas1, teks, getCurrTime());
    }
    printf("===============================CHECK POINT =============================\n");

    printf("Input Rusdi\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", &teks);
        insertLastThreadForConfig(utas2, teks, getCurrTime());
    }

    printf("Input Sahad\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", &teks);
        insertLastThreadForConfig(utas3, teks, getCurrTime());
    }

    // Create Utas
    displayUtas(utas1);
    displayUtas(utas2);
    displayUtas(utas3);

    // Create List Utas
    printf("OUTPUT\n");
    ListUtas utases;
    CreateListUtas(&utases, 100);

    insertUtas(utas1, &utases);
    // printf("%d\n", listUtasLength(utases));
    insertUtas(utas2, &utases);
    // printf("%d\n", listUtasLength(utases));
    insertUtas(utas3, &utases);
    // printf("%d\n", listUtasLength(utases));

    printf("########################### DISPLAY FROM LIST DINAMIS ###########################\n");

    for (int i = 0; i < listUtasLength(utases); i++)
    {
        displayUtas(BUFFERListDinUtas(utases)[i]);
    }
    printf("%d\n", CAPACITYListDinUtas(utases));

    // printf("Length NEFF list : %d\n", listUtasLength(utases));

    // displayUtas(BUFFERListDinUtas(utases)[0]);
}