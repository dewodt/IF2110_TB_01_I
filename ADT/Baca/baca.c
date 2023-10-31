#include "../wordmachine/wordmachine.c"
#include "../charmachine/charmachine.c"
#include "../boolean.h"

void baca(Word *kata){
    printf("\n");
    ADVWORD();
    *kata = currentWord;
}

boolean isSame(Word kata1, char fungsi[]){
    boolean hasil;
    hasil = true;
    int i;
    i = 0;
    while ((i < kata1.Length) && hasil)
    {
        if(kata1.TabWord[i] != fungsi[i]){
            hasil = false;
        }
    }
    return hasil;
}