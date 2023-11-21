
// #include "../masukan/masukan.c"
// #include "../charmachine/charmachine.c"
// #include "../listlinierUtas/listlinierForUtas.c"
// #include "../listdinUtas/listdinForUtas.c"
// #include "../listdinkicauan/listdinkicauan.c"
// #include "../datetime/datetime.c"
// #include "../time/time.c"
// #include "utas.c"

// /* GLOBAL VARIABLES */
// ListDinKicauan listKicauan;
// ListStatik listUser;
// ListUtas listUtas;
// User *currentUser;

// int main()
// {
//     // Construct User secara manual
//     User Messi;
//     strcpy(Messi.username, "Bang Leo");

//     printf("%s", Messi.username);

//     // construct thread
//     // threads tweet;
//     // CreateThreads(&tweet);
//     // printf("Sukses ccreate threads\n");
//     // for (int i = 0; i < 3; i++)
//     // {
//     //     insertLastThreads(&tweet, "Haloo");
//     // }
//     // displayThreads(tweet, Messi.username);

//     // Construct Kicauan
//     Kicauan kicau;
//     kicau.id = 1;
//     strcpy(kicau.text, "Lelahh tubes");
//     kicau.like = 99;
//     kicau.author = &Messi;
//     kicau.datetime = getCurrTime();

//     // Construct utas
//     UTAS utas;
//     CreateUtas(&utas, &kicau, 1);
//     printf("\n");
//     displayUtas(utas);

//     SambungUtasLast(&utas, "skidipapap 1");
//     SambungUtasLast(&utas, "skidipapap 2");
//     SambungUtasLast(&utas, "skidipapap 3");
//     SambungUtasLast(&utas, "skidipapap 4");

//     // printf("\n");
//     // displayUtas(utas);

//     // HapusUtasAt(&utas, 1);
//     // displayUtas(utas);

//     // printf("Sambung utas at 2\n");
//     // baca(&teks);
//     // SambungUtasAt(&utas, MASUKANToStr(teks), 1);
//     // displayUtas(utas);

//     // Construct list Utas
//     ListUtas lu;
//     CreateListUtas(&lu, 5);
//     insertUtas(&lu, utas);
//     insertUtas(&lu, utas);
//     insertUtas(&lu, utas);

//     displayUtas(BUFFERListDinUtas(lu)[0]);
//     // displayUtas(utas);

//     // HapusUtasAt(&BUFFERListDinUtas(lu)[0], 1);
//     // displayUtas(BUFFERListDinUtas(lu)[0]);

//     // displayUtas(BUFFERListDinUtas(lu)[0]);

//     // HapusUtasAt(&utas, 1);
//     // insertUtas(&lu, utas);
//     // displayUtas(BUFFERListDinUtas(lu)[1]);

//     // displayUtas(BUFFERListDinUtas(lu)[0]);

//     // Buat List Kicauan
//     ListDinKicauan lk;
//     CreateListDinKicauan(&lk, 10);

//     BUAT_UTAS()
// }