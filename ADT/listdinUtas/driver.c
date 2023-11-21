#include "listdinForUtas.c"
#include "../listlinierUtas/listlinierForUtas.c"
#include "../datetime/datetime.c"
#include "../time/time.c"
#include "../masukan/masukan.c"
#include "../charmachine/charmachine.c"
#include "../tree/tree.h"

int main()
{
    // Construct User secara manual
    User Messi;
    strcpy(Messi.username, "Bang Leo");

    printf("%s", Messi.username);

    // construct thread
    // threads tweet;
    // CreateThreads(&tweet);
    // printf("Sukses ccreate threads\n");
    // for (int i = 0; i < 3; i++)
    // {
    //     insertLastThreads(&tweet, "Haloo");
    // }
    // displayThreads(tweet, Messi.username);

    // Construct Kicauan
    Kicauan kicau;
    kicau.id = 1;
    strcpy(kicau.text, "Lelahh tubes");
    kicau.like = 99;
    kicau.author = &Messi;
    kicau.datetime = getCurrTime();

    // Construct utas
    UTAS utas;
    CreateUtas(&utas, &kicau, 1);
    printf("\n");
    displayUtas(utas);

    SambungUtasLast(&utas, "Testting 1");
    SambungUtasLast(&utas, "Testting 2");
    SambungUtasLast(&utas, "Testting 3");
    SambungUtasLast(&utas, "Testting 4");

    MASUKAN input;

    // UTAS utas2;
    // CreateUtas(&utas, &kicau, 1);
    // printf("\n");
    // displayUtas(utas);

    // SambungUtasLast(&utas, "Testting 1");
    // SambungUtasLast(&utas, "Testting 2");
    // SambungUtasLast(&utas, "Testting 3");
    // SambungUtasLast(&utas, "Testting 4");

    // printf("\n");
    // displayUtas(utas);

    // HapusUtasAt(&utas, 1);
    // displayUtas(utas);

    // printf("Sambung utas at 2\n");
    // baca(&teks);
    // SambungUtasAt(&utas, MASUKANToStr(teks), 1);
    // displayUtas(utas);

    // Construct list Utas
    // ListUtas lu;
    // CreateListUtas(&lu, 5);
    // insertUtas(&lu, utas);
    // insertUtas(&lu, utas);
    // insertUtas(&lu, utas);

    // displayUtas(BUFFERListDinUtas(lu)[0]);
    // displayUtas(utas);

    // HapusUtasAt(&BUFFERListDinUtas(lu)[0], 1);
    // displayUtas(BUFFERListDinUtas(lu)[0]);

    // displayUtas(BUFFERListDinUtas(lu)[0]);

    // displayUtas(BUFFERListDinUtas(lu)[0]);
}
