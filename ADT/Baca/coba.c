#include "baca.c"

int main(){
    Word kata;
    baca(&kata);
    while (!isSame(kata, "\nTUTUP_PROGRAM;")) {
        displayKata(kata);
        printf("\n");
        break;
    }
    
    return 0;
}