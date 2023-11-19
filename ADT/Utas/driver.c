
#include "../masukan/masukan.c"
#include "../charmachine/charmachine.c"
#include "../listlinierUtas/listlinierForUtas.c"
#include "../listdinUtas/listdinForUtas.c"
#include "utas.c"

/* GLOBAL VARIABLES */
ListDinKicauan listKicauan;
ListStatik listUser;
ListUtas listUtas;
User *currentUser;

int main()
{
    // Inisialisasi global variable
    CreateListDinKicauan(&listKicauan, 100);
    CreateListUtas(&listUtas, 100);
    CreateListStatik(&listUser);
    currentUser = NULL;

    User Messi;
    strcpy(Messi.username, "Messiiuuu");
    strcpy(Messi.password, "ROnaldoccd");
    strcpy(Messi.bio, "8 Ballon d'or babyy");
    strcpy(Messi.weton, "Kliwon");

    Kicauan kicau;
    ID(kicau) = 1;
    AUTHOR(kicau) = &Messi;
    strcpy(TEXT(kicau), "Stamina mina ee");
    DATETIME(kicau) = getCurrTime();

    ListDinKicauan listkicau;
    CreateListDinKicauan(&listkicau, 10);
    insertLastListDinKicauan(&listkicau, &kicau);

    BUAT_UTAS(1, listkicau, Messi);
}