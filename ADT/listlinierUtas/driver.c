
// #include "listlinierForUtas.c"
// #include "../datetime/datetime.c"
// #include "../time/time.c"
// #include "../masukan/masukan.c"
// #include "../charmachine/charmachine.c"
// #include "../tree/tree.h"

// boolean isUtasUser(UTAS u, User userloggedin)
// {
//     return (isSame(strToMASUKAN(AuthorUtas(u), 20), userloggedin.username));
// }

// boolean isKicauanUser(Kicauan k, User userloggedin)
// {
//     return (isSame(strToMASUKAN((*AUTHOR(k)).username, 20), userloggedin.username));
// }

// int main()
// {
//     // Construct User secara manual
//     User Ronaldo;
//     strcpy(Ronaldo.username, "Siuuu");

//     printf("%s", Ronaldo.username);

//     User Messi;
//     strcpy(Messi.username, "Bang Leo");

//     printf("%s", Messi.username);

//     // construct thread
//     threads tweet;
//     CreateThreads(&tweet);
//     printf("Sukses ccreate threads\n");
//     for (int i = 0; i < 3; i++)
//     {
//         insertLastThreads(&tweet, "Haloo");
//     }
//     displayThreads(tweet, Messi.username);

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

//     char test[280] = "Pampramprapmpam";
//     insertLastThreadForConfig(&utas, test, getCurrTime());

//     displayUtas(utas);

//     // MASUKAN teks;
//     // for (int i = 0; i < 2; i++)
//     // {
//     //     baca(&teks);
//     //     SambungUtasLast(&utas, MASUKANToStr(teks));
//     // }
//     // printf("\n");
//     // displayUtas(utas);

//     // // HapusUtasAt(&utas, 1);
//     // // displayUtas(utas);

//     // boolean testing = isKicauanUser(kicau, Ronaldo);
//     // printf("TESTING %d", testing);

//     // MASUKAN test;
//     // baca(&test);
//     // printf("%s", MASUKANToStr(test));

//     // baca(&test);
//     // printf("%s", MASUKANToStr(test));
// }