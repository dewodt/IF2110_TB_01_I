
#include "../masukan/masukan.c"
#include "../charmachine/charmachine.c"
#include "../listlinierUtas/listlinierForUtas.c"
#include "../listdinUtas/listdinForUtas.c"

int main()
{
    MASUKAN text;
    baca(&text);
    printf("%s", text.TabMASUKAN);
}